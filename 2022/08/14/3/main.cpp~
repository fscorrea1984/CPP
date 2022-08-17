#include<iostream>
#include<algorithm>
#include<limits>
#include<sstream>
#include<string>
#include<utility>
#include<vector>
#include<cassert>


//#include <bits/stdc++.h>

using namespace std;

void build(int M[], int t[], int v, int tl, int tr) {

  if(tl == tr)
    t[v] = M[tl];
  else {
      int L = v*2+1;
      int R = v*2+2;
      int tm = (tl + tr)/2;

      build(M,t,v*2+1,tl,tm);
      build(M,t,v*2+2,tm+1,tr);

      t[v] = max(t[L],t[R]);
  }
	
}

void push(int t[], int lazy[], int v) {

  t[v*2+1] += lazy[v];
  lazy[v*2+1] += lazy[v];

  t[v*2+2] += lazy[v];
  lazy[v*2+2] += lazy[v];

  lazy[v] = 0;
  
}

void update(int t[], int lazy[], int v, int tl, int tr, int l, int r, int addend) {

  if(l > r)
    return;
  
  if(l == tl && tr == r) {
    t[v] += addend;
    lazy[v] += addend;
  }
  else {
    push(t, lazy, v);
    
    int L = v*2+1;
    int R = v*2+2;
    int tm = (tl+tr)/2;
    
    update(t, lazy, v*2+1, tl, tm, l, min(r,tm), addend);
    update(t, lazy, v*2+2, tm+1, tr, max(l,tm+1), r, addend);

    t[v] = max(t[L],t[R]);
  }
  
}

int query(int t[], int lazy[], int v, int tl, int tr, int l, int r) {

  if(l > r)
    return numeric_limits<int>::min();
  
  if(l <= tl && tr <= r) // [l [tl tr] r]
    return t[v];
  
  push(t, lazy, v);
  
  int tm = (tl+tr)/2;
  
  return max(query(t, lazy, v*2+1, tl, tm, l, min(r,tm)),query(t, lazy, v*2+2, tm+1, tr, max(l,tm+1), r));
  
}

int main(int argc, char **argv) {

  /*
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  */

  string str;

  while(getline(cin,str)) {

    stringstream arc(str);

    int N, Q;

    arc >> N >> Q;

    int* M = new int[N];

    for(int i = 0; i < N; i++) {
      int m;

      cin >> m;
      M[i] = m;
      
    }

    int* t = new int[4*N];
    int* lazy = new int[4*N];

    build(M,t,0,0,N-1);

    for(int i = 0; i < Q; i++) {
      char a;
      int b, c, d;

      cin >> a;

      if(a == 'A') {
	cin >> b >> c >> d;
	update(t, lazy, 0, 0, N-1, b-1, c-1, d);
      }
      
      if(a == 'C') {
	cin >> b >> c;
	int q = query(t, lazy, 0, 0, N-1, b-1, c-1);
	//q++;
	//cout << "max [" << b << "," << c << "] = " << q << endl;
      }

          /*    for(int i = 0; i < 9; i++)
      cout << "t[" << i << "] = (" << t[i].key << "," << t[i].val << ")" << endl; */
      
    }

    /*    for(int i = 0; i < 9; i++)
      cout << "t[" << i << "] = (" << t[i].key << "," << t[i].val << ")" << endl; */

    delete[] M;
    delete[] t;
    delete[] lazy;

  }

  return 0;
  
}
