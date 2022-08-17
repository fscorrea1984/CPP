#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <vector>

using namespace std;

int main(int argc, char **argv) {

  int i,j,x,y;
  string line = " ", dummy;
  int N; //,count = 1;
  bool perfect = false;

  getline(cin,line);
  stringstream str(line);
  str >> N;

  vector<stringstream> ss(N);

  for(i = 0; i < N; i++) {
    int count = 0;
    getline(cin,line);
    ss[i].str(line);
    ss[i] >> x;
     
    for(j = 1; j < x; j++)
      if(x % j == 0)
	count += j;

    if(x == count)
      cout << x << " eh perfeito" << endl;
    else
      cout << x << " nao eh perfeito" << endl;

  }
  
  return 0;

}
