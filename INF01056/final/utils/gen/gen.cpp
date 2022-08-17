/*-- gen.cpp --*/

//alpha { 0.2 , 0.4 , 0.6 , 0.8 , 1.0 , 1.25 , 1.5 , 1.75 , 2.0 , 3.0 }

// { 80 , 100 , 120 , 140 , 160 , 180 , 200 } x { (0 , 100) , (25 , 75) } x { 50 , 100 , 150 , 200 , ... , 450 , 500 } x { 0.5 , 0.8 , 1.1 , 1.4 , 1.7 , 2.0 }

// { 70 , 80 , 90 , 100 } x { 5 , 10 , 15 , 20 , 25, 30 }

#include<iostream>
#include<string>
#include<random>
#include<vector>
#include<algorithm> //sort

using namespace std;

vector<int> R, D, W;
int n, p;

int main (int argc, char **argv) {

  bool agreeable = false;
  
  if (argc == 4) {
    n = stoi(argv[2]);
    p = stoi(argv[3]);
    string flag(argv[1]);
    if ((flag != "-G") && (flag != "--agreeable")) goto usage;
    else agreeable = true;
  }
  else
    if (argc == 3) {
      n = stoi(argv[1]);
      p = stoi(argv[2]);
    }
    else {
    usage:
      cerr <<  "usage: gen [-G --agreeable] N P" << endl;
      return 1;
    }
  
  random_device gen;
  mt19937 mt(gen());

  //default_random_engine gen;
  uniform_int_distribution<int> wd(1,120);
  uniform_int_distribution<int> rd(1,(n-6)*p); //rd = release (dates) distribution
  cout << "c this is a comment line" << endl;
  cout << "n p " << n << " " << p << endl;
  for (unsigned j = 1; j <= n; j++) {
    int rj = rd(gen);
    uniform_int_distribution<int> dd(rj+p,(n-5)*p);
    int dj = dd(gen);
    int wj = wd(gen);
    R.push_back(rj);
    D.push_back(dj);
    W.push_back(wj);
  }

  if (agreeable) {
    sort (R.begin(), R.end(), [] (const int & a, const int & b) -> bool { return a < b; } );
    sort (D.begin(), D.end(), [] (const int & a, const int & b) -> bool { return a < b; } );
  }
  
  for (unsigned j = 0; j < n; j++)
    cout << "j " << R[j] << " " << D[j] << " " << W[j] << endl;
  
  return 0;

}
