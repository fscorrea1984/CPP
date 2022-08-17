#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {

  string line;

  getline(cin,line);

  int N = stoi(line,nullptr,10);

  for(int i = 0; i < N; i++) {
    getline(cin,line);
    stringstream str(line);
    int X,Y,Z = 0;
    str >> X >> Y;
    X += (X % 2)? 0 : 1;
    for(int j = 0; j < Y; j++) {
      Z += X;
      X += 2;
    }
    cout << Z << endl;
  }

  return 0;

}
