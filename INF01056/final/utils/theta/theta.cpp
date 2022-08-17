/* -- theta.cpp -- */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <limits>

using namespace std;

const int inf_min = numeric_limits<int>::min();

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

  int n = 0;
  int p = 0;

  string line = "", dummy;
  string filename;
  char ac;
  int a, b, c;

    if (argc == 2) filename = argv[1];
  else {
    cerr << "usage: bap FILE" << endl;
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

  sort (J.begin(), J.end(), [] (const Job & a, const Job & b) -> bool { return (a.getd() != b.getd()) ? (a.getd() < b.getd()) : (a.getr() < b.getr()); } );

  vector<int> theta (1,inf_min);

  //1: Build theta
  for (int i = 1; i <= n; i++) {
    int t = J[i].getr();
    theta.push_back(t); //put r[i] in theta
    for (int l = 1; l <= n; l++) {
      t += p; //t = r[i] + l*p
      theta.push_back(t); //put (r[i] + l*p) in theta
    }
  }

  sort (theta.begin(), theta.end());

  auto last = unique (theta.begin(), theta.end());
  theta.erase(last, theta.end());

  theta.at(0) = theta.at(1) - p;

  const int T = theta.size();

  cout << T << endl;
  
  /* TODO
  for (int i = 0; i < T; i++)
    cout << "Theta[" << i << "] == " << theta.at(i) << endl;
*/
  
  return 0;

}
