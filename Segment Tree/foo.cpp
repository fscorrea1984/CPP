#include <iostream>
#include <string>
#include <sstream>
#include "st.h"

using namespace std;

int main() {

  int N,Q;
  int *arr;
  SegTree *ST;
  //string line = "";
  
  while(!cin.eof()) {
    cin >> N;

    //str >> N;

    arr = new int[N];

    for(int i = 0; i < N; i++) {
      cin >> arr[i];
      //getline(cin,line);
      //stringstream str(line);
      //str >> arr[i];
    }

    ST = new SegTree(arr,N);

    delete arr;

    cin >> Q;

    for(int i = 0; i < Q; i++) {
      int a,b,c;
      cin >> a;
      cin >> b;
      cin >> c;
      if(a == 1)
	ST->update(b-1,c);
      if(a == 2) {
	cout << ST->query(b-1,c-1) << endl;
      }
    }

    delete ST;
    
  }

  return 0;

}
