#include<iostream>
#include<string>
#include<random>
#include<vector>
#include<algorithm> //sort

using namespace std;
/*
vector<string> V;
vector<string>::iterator it;
int n;
char c1, c2;
string str, K;
*/
bool isInV(vector<string> vs, const string & s) {
  vector<string>::iterator it;
  for(it = vs.begin(); it != vs.end(); it++)
    if(*it == s)
      return true;
  return false;
}

int main (int argc, char **argv) {

  vector<string> V;
  vector<string>::iterator it;
  int n;
  char c1, c2;
  string str = "", K = "";
  
  if(argc != 2) {
    cerr << "Usage: gen number_of_test_cases" << endl;
    return 1;
  }

  n = stoi(argv[1]);

  random_device gen;
  mt19937 mt(gen());

  uniform_int_distribution<int> rd(2,7);
  uniform_int_distribution<int> cd(0x61,0x68);
  uniform_int_distribution<int> Kd(1,8);

  for(int i = 0; i < n; i++) {
    c1 = static_cast<char>(Kd(gen)+0x30);
    K += c1;
    c2 = static_cast<char>(cd(gen));
    K += c2;
    cout << K << endl;
    V.push_back(K);
    do {
      str.clear();
      str = "";
      c1 = static_cast<char>(rd(gen)+0x30);
      str.push_back(c1);
      c2 = static_cast<char>(cd(gen));
      str.push_back(c2);
      if((str != K) && !(isInV(V,str)))
	V.push_back(str);
    } while (V.size() < 8);
    str.clear();
    str = "";
    sort(V.begin(), V.end(), [] (const string & a, const string & b) -> bool { return a < b; } );
    for(it = V.begin(); it != V.end(); it++)
      cout << *it << endl;
    V.clear();
  }

  cout << 0 << endl;

  return 0;

}
