#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {

  map<int,char> AtoR = {
			{ 1, 'I' },
			{ 5, 'V' },
			{ 10, 'X' },
			{ 50, 'L' },
			{ 100, 'C' },
			{ 500, 'D' },
			{ 1000, 'M' }
  };

  string line;

  getline(cin,line);

  if (line.length() > 3) {
    cerr << "Error: N must have at most three digits" << endl;
    terminate();
  }

  if (line.length() < 1) {
    cerr << "Error: N must be between 0 and 999" << endl;
    terminate();
  }

  if(line.length() < 3)
    while(line.length() != 3)
      //line.push_back('0');
      line.insert(0,"0");

  int X = 100;
  
  for(int i = 0; i < 3; i++) {
    
    unsigned char ch = static_cast<unsigned char>(line.at(i));
    unsigned int c = static_cast<unsigned int>(ch) - 0x30;

    if(c == 4 || c == 9) {
      cout << AtoR.at(X) << AtoR.at(X*(c+1));
      X /= 10;
      continue;
    }

    if(c > 4) {
      cout << AtoR.at(5*X);
      c -= 5;
    }
  
    if(c >= 1 && c <= 3)
      for(int j = 0; j < c; j++)
	cout << AtoR.at(X);

    X /= 10;
  
  }

  cout << endl;
  
  return 0;
  
}
