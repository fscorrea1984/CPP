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

  getline(cin,line);
  stringstream str(line);
  str >> N;

  vector<stringstream> ss(N);

  for(i = 0; i < N; i++) {
    int count = 1;
    getline(cin,line);
    ss[i].str(line);
    ss[i] >> x;
 

    double d(x);
    y = static_cast<int>(floor(sqrt(x)));
    for(j = 2; j < y; j++) 
      if(x % j == 0)
	count += (j == x/j)? j : (j + x/j) ;

    //cout << "X = " << count << endl;
    cout << "y = " << count << endl;
    cout << "line = " << count << endl;
    cout << "X = " << count << endl;

  }
  
  return 0;

}





	/*if(x/j == j)
	divisors.push_back(j);
	else {
	  divisors.push_back(j);
	  divisors.push_back(x/j);
	*/ //}
