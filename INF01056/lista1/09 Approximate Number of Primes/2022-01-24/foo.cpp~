#include <iostream>
#include <string>

using namespace std;

int main() {

  string line;

  getline(cin,line);

  unsigned long N = stol(line,nullptr,10);

  if(N <= 5 || N >= 2000) {
    cerr << "N is out of range" << endl;
    terminate();
  }

  for(int i = 2; i <= N; i += 2)
    cout << i << "^2 = " << i*i << endl;

  return 0;

}
