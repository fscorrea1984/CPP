#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {

  string line;

  getline(cin,line);

  double n = stod(line,nullptr);

  if(n < 17 || n > pow(10,9)) {
    cerr << "n is out of range" << endl;
    terminate();
    }

  double P = n/(log(n));

  double M = 1.25506 * P;

  cout.precision(1);

  cout << fixed << P << " " << M << endl;

  return 0;

}
