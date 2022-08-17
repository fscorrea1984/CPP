#include <iostream>
#include <string>
#include <random>

using namespace std;

int main(int argc, char **argv) {

  int n, p;
  string str = "";

/*  if(argc != 3)
    terminate();*/

  random_device gen;
  mt19937 mt(gen());

  //uniform_int_distribution<int> dn(1,9999);
  //uniform_int_distribution<int> dp(1,10);
  //uniform_int_distribution<int> ds(1,100);
  uniform_int_distribution<int> dc(0x61,0x7A);
  
  //n = dn(gen);
  //p = dp(gen);
  
  for(int q = 1; q <= 1; q++) {
    cout << 9999 << endl;
    for(int i = 0; i < 9999; i++) {
      //int m = ds(gen);
      char c;
      for(int j = 1; j <= 100; j++) {
	c = static_cast<char>(dc(gen));
	str += c;
      }
      cout << str << endl;
      str = "";
    }
  }

  cout << "0" << endl;

  return 0;
  
}
