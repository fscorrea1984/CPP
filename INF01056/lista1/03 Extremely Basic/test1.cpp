#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char **argv) {

  int A,B;
  string line = " ", dummy;
  
  getline(cin,line);
  stringstream ss1(line);
  ss1 >> A;
  getline(cin,line);
  stringstream ss2(line);
  ss2 >> B;

  //cout << "A = " << A << endl;
  //cout << "B = " << B << endl;
  cout << "X = " << A+B << endl;

  return 0;

}
