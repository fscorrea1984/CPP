/** -- Test whether a given instance (usually, a file ".in" in "inst" folder) satisfies "agreeable release and due dates" or not  -- **/

/** -- The name "inst-chkr" comes from "INSTance-CHecKeR" -- **/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

class Job {

public:

  void setr (int x) { r = x; }
  void setd (int x) { d = x; }
  void setw (int x) { w = x; }

  int getr () const { return r; } 
  int getd () const { return d; }
  int getw () const { return w; }
  
  Job ();
  Job (int, int, int);
  ~Job () {}
  
private:
  int r, d, w;
  
};

Job::Job () : r(0), d(0), w(0) {};

Job::Job (int a, int b, int c) : r(a), d(b), w(c) {};

int main (int argc, char **argv) {

  int n, p;
  string line = "", dummy;
  string filename;
  char ac;
  int a, b, c;

    if (argc == 2) filename = argv[1];
    else {
      cerr << "usage: inst-chkr FILE" << endl;
      terminate();
    }
  
  ifstream ifile;

  ifile.open(filename);

  while (line.substr(0,3) != "n p")
    getline (ifile, line);
  stringstream linestr(line);
  linestr >> dummy >> dummy >> n >> p;

  vector<Job> J;
  J.push_back(Job());

  for (int i = 1; i <= n; i++) {
    getline (ifile, line);
    if (line.substr(0,2) == "j ") {
      stringstream job(line);
      job >> ac >> a >> b >> c;
      J.push_back(Job(a, b, c));
    }
  }

  sort (J.begin(), J.end(), [] (const Job & a, const Job & b) -> bool { return a.getd() < b.getd(); } );

  ifile.close();

  //after this, J is already sorted by due date, so just iterate over release dates:
  for (int k = 2; k <= n; k++){

    if ( (J[k-1].getr() > J[k].getr()) && (J[k-1].getd() != J[k].getd()) ) {
	cout << "This set of jobs has \"non-agreeable\" release and due dates." << endl;
	return 0;
    } //end if
    
  } // end for

  cout << "This set of jobs has \"agreeable\" release and due dates." << endl;
  
  return 0;

}
