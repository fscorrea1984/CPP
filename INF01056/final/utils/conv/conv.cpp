/*-- conv.cpp --*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <limits>
#include <algorithm>
#include <exception>

using namespace std;

const int inf_min = numeric_limits<int>::min();

int main (int argc, char **argv) {

  unsigned n, p;

  string line = " ", dummy;
  string filename(argv[1]);
  char ac;
  unsigned a, b, c;
  unsigned i = 1;

  ifstream ifile(filename);

  while (line.substr(0,3) != "n p")
    getline (ifile, line);
  stringstream linestr(line);
  linestr >> dummy >> dummy >> n >> p;
  cout << "param n := " << n << ";" << endl;
  cout << "param p := " << p << ";" << endl;
  cout << "param:" << '\t' << "r" << '\t' << "d" << '\t' << "w" << "\t:=" << endl;

  vector<int> R (n+1,0); //R is 1-based
  int r = 0;

  while (i <= n) {
    getline (ifile, line);
    if (line.substr(0,2) == "j ") {
      stringstream job(line);
      job >> ac >> a >> b >> c;
      cout << i << '\t' << a << '\t' << b << '\t' << c << endl;
      r = (int)a;
      R.at(i) = r;
      i++;
    }
  }

  cout << ";" << endl;
  ifile.close();

  vector<int> theta (1,inf_min); //theta is 1-based then has a dummy null zeroth element theta[0] = 0

  //1: Build theta
  for (int i = 1; i <= n; i++) {
    int t = R[i];
    theta.push_back(t); //put r[i] in theta
    for (int l = 1; l <= n; l++) {
      t += p; //t = r[i] + l*p
      theta.push_back(t); //put (r[i] + l*p) in theta
    }
  }

  //2: Sort theta
  sort (theta.begin(), theta.end());

  //3: Remove duplicate entries from theta
  auto last = unique (theta.begin(), theta.end());
  theta.erase(last, theta.end());

  cout << endl;
  cout << "set THETA :=";

  for (i = 1; i < theta.size(); i++)
    cout << " " << theta.at(i);
  cout << " ;" << endl;

  for (i = 1; i < theta.size(); i++) {
    unsigned aux = i + 1;
    cout << "set H[" << theta.at(i) << "] := " << theta.at(i);
    if (aux >= theta.size()) { //trying to access position aux = i + 1 in vector would be illegal, then put a ";" and break
      cout << " ;" << endl;
      break;
    }
    if (theta.at(aux) >= theta.at(i) + p) { //for this i, the first element after him, i+1, is already non-conflicting, hence H[i] shall remain unitary
      cout << " ;" << endl;
      continue;
    }
    while ( (aux < theta.size()) && (theta.at(aux) < theta.at(i) + p) ) {
      cout << " " << theta.at(aux);
      aux++;
    }
    cout << " ;" << endl;
  }

  cout << endl << "end;" << endl;

  return 0;

}
