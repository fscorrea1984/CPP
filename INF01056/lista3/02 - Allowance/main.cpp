#include<iostream>
#include<algorithm>
#include<string>
#include<utility>
#include<vector>
#include<cmath>
#include"maxst.h"

using namespace std;

int main(int argc, char **argv) {

  while(true) {

    //check if end-of-file
    if(cin.eof()) break;

    int N, Q;
    
    //read number of children and number of operations
    cin >> N >> Q;

    //calculate maxst size
    int h = static_cast<int>(ceil(log2(N)));
    int S = static_cast<int>(pow(2,h));
    S *= 2;
    S--;

    vector<int> M;

    //read elements of M
    for(int i = 0; i < N; i++) {
      int m;
      cin >> m;
      M.push_back(m);
    }

    pair<int,int> range(0,N-1);

    MST maxst(M,range,0,S);

    //read operations
    for(int i = 0; i < Q; i++) {
      char a;
      int b, c, d;
      cin >> a;
      if(a == 'A') {
	cin >> b >> c >> d;
	b--;
	c--;
	range = make_pair(b,c);
	maxst.update(range,0,d);
      }
      if(a = 'C') {
	cin >> b >> c;
	b--;
	c--;
	range = make_pair(b,c);
	pair<int,int> q = maxst.query(range,0);
	cout << q.second << endl;
      }
    }
    
  }
  return 0;
  
}
