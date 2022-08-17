#include<iostream>
#include<algorithm>
#include<sstream>
#include<string>
#include<utility>
#include<vector>
#include<cassert>


//#include <bits/stdc++.h>

using namespace std;

class node {

public:
  int key = -1;
  int val = -1; // value
  int lazy = 0;
};

int N, Q;

void build(int M[], node t[], int v, int tl, int tr) {
  if(tl == tr) {
    t[v].key = tl;
    t[v].val = M[tl];
  } else {
      int L = v*2+1;
      int R = v*2+2;
      int tm = (tl + tr)/2;

      build(M,t,v*2+1,tl,tm);
      build(M,t,v*2+2,tm+1,tr);

      if(t[L].val == t[R].val)
	t[v] = (t[L].key < t[R].key) ? t[L] : t[R];
      else
	t[v] = (t[L].val > t[R].val) ? t[L] : t[R];
  }
}

void push(node t[], int v) {

  //if(t[v*2+1].key > 0) {
  t[v*2+1].val += t[v].lazy;
  t[v*2+1].lazy += t[v].lazy;
  //}

  //if(t[v*2+2].key > 0) {
  t[v*2+2].val += t[v].lazy;
  t[v*2+2].lazy += t[v].lazy;
  //}
  
  t[v].lazy = 0;
  
}

void update(node t[], int v, int tl, int tr, int l, int r, int addend) {

  if(l > r)
    return;
  
  if(l == tl && tr == r) {
    t[v].val += addend;
    t[v].lazy += addend;
  } else {
    push(t,v);
    
    int L = v*2+1;
    int R = v*2+2;
    int tm = (tl+tr)/2;
    
    update(t, v*2+1, tl, tm, l, min(r,tm), addend);
    update(t, v*2+2, tm+1, tr, max(l,tm+1), r, addend);

    if(t[L].val == t[R].val) {
      if(t[L].key < t[R].key) {
	t[v].key = t[L].key;
	t[v].val = t[L].val;
      } else {
	t[v].key = t[R].key;
	t[v].val = t[R].val;
      }
    } else {
      if(t[L].val > t[R].val) {
	t[v].key = t[L].key;
	t[v].val = t[L].val;
      } else {
	t[v].key = t[R].key;
	t[v].val = t[R].val;
      }
    }
  }
  
}

pair<int,int> query(node t[], int v, int tl, int tr, int l, int r) {

  if(l > r)
    return make_pair(-1,-1);
  
  if(l <= tl && tr <= r)
    return make_pair(t[v].key,t[v].val);
  
  push(t,v);
  
  int tm = (tl+tr)/2;
  
  pair<int,int> ql = query(t, v*2+1, tl, tm, l, min(r,tm));
  pair<int,int> qr = query(t, v*2+2, tm+1, tr, max(l,tm+1), r);

  if(ql.second == qr.second)
    return (ql.first < qr.first) ? ql : qr;
  else
    return (ql.second > qr.second) ? ql : qr;
  
}

int main(int argc, char **argv) {

  /*
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  */

  string str;

  //while(getline(cin,str)) {

  while(cin >> N >> Q) {
    //stringstream arc(str);

    //int N, Q;

    //arc >> N >> Q;

    int* M = new int[N];

    for(int i = 0; i < N; i++) {
      int m;

      cin >> m;
      M[i] = m;
      
    }

    node* t = new node[4*N];

    build(M,t,0,0,N-1);

    for(int i = 0; i < Q; i++) {
      char a;
      int b, c, d;

      cin >> a;

      if(a == 'A') {
	cin >> b >> c >> d;
	update(t, 0, 0, N-1, b-1, c-1, d);
      }
      
      if(a == 'C') {
	cin >> b >> c;
	pair<int,int> q = query(t, 0, 0, N-1, b-1, c-1);
	q.first++;
	cout << q.first << endl;
      }
      
    }

    /*    for(int i = 0; i < 9; i++)
      cout << "t[" << i << "] = (" << t[i].key << "," << t[i].val << ")" << endl; */

    delete[] M;
    delete[] t;

  }

  return 0;
  
}
