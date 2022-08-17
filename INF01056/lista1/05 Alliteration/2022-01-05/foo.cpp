#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {

  string line;
  //char ch;

  while(getline(cin,line)) {
    stringstream str(line);
    bool flag = false;
    int count = 0;
    while(true){
      //char curr = '\0';
      char curr;
      string a;
      str >> a;
      if (a.empty()) break;
      if ((tolower(curr) == tolower(a.front())) && !flag) {
	flag = true;
	count++;
      }
      else if (tolower(curr) != a.front()) flag = false;
      curr = a.front();
    }
    cout << count << endl;
  }

  return 0;
  
}
