#include<iostream>
#include<algorithm>
#include<sstream>
#include<string>
#include<utility>
#include<vector>
#include<cassert>

using namespace std;

class node {

public:
  int key = -1;
  int val = -1; // value
  int lazy = 0;
};

int compare(int[],node[],int,int);
int n;

void build(int M[], node t[], int v, int tl, int tr) {
  if(tl == tr) {
    t[v].key = tl;
    t[v].val = M[tl];
  } else {
    int tm = (tl + tr)/2;
    build(M,t,v*2+1,tl,tm);
    build(M,t,v*2+2,tm+1,tr);
    t[v].key = compare(M, t, t[v*2+1].key, t[v*2+2].key);
    t[v].val = M[t[v].key];
  }
}

void push(node t[], int v) {

  if(t[v*2+1].key > 0) {
  t[v*2+1].val += t[v].lazy;
  t[v*2+1].lazy += t[v].lazy;
  }

  if(t[v*2+2].key > 0) {
  t[v*2+2].val += t[v].lazy;
  t[v*2+2].lazy += t[v].lazy;
  }
  
  t[v].lazy = 0;
  
}

void update(int M[], node t[], int v, int tl, int tr, int l, int r, int addend) {
  if(l > r)
    return;
  if(l == tl && tr == r) {
    t[v].val += addend;
    t[v].lazy += addend;
  } else {
    push(t,v);
    int tm = (tl+tr)/2;
    update(M, t, v*2+1, tl, tm, l, min(r,tm), addend);
    update(M, t, v*2+2, tm+1, tr, max(l,tm+1), r, addend);
    t[v].key = compare(M, t, t[v*2+1].key, t[v*2+2].key);
    t[v].val = M[t[v].key];
  }
}

int query(int M[], node t[], int v, int tl, int tr, int l, int r) {
  if(l > r)
    return -1;
  if(l <= tl && tr <= r)
    return t[v].key;
  push(t,v);
  int tm = (tl+tr)/2;
  int ql = query(M, t, v*2+1, tl, tm, l, min(r,tm));
  int qr = query(M, t, v*2+2, tm+1, tr, max(l,tm+1), r);
  int res = compare(M, t, ql, qr);
  return res;
}

int compare(int M[], node t[], int x, int y) {

  assert(x < n);
  assert(y < n);
  
  if(x < 0)
    return y;
  if(y < 0)
    return x;
  if((x < 0) && (y < 0))
    return -1;
  
  if(M[x] == M[y])
    return (x < y) ? x : y;
  else
    return( M[x] > M[y]) ? x : y;
  
}

int main(int argc, char **argv) {

  string str;

  while(getline(cin,str)) {

    stringstream arc(str);

    int N, Q;

    arc >> N >> Q;

    n = N;

    int M[N];

    for(int i = 0; i < N; i++) {
      int m;
      cin >> m;
      M[i] = m;
    }

    node t[4*N];
    
    build(M,t,0,0,N-1);

    for(int i = 0; i < Q; i++) {
      char a;
      int b, c, d;
      cin >> a;
      if(a == 'A') {
	cin >> b >> c >> d;
	update(M, t, 0, 0, N-1, b-1, c-1, d);
      }
      if(a == 'C') {
	cin >> b >> c;
	int q = query(M, t, 0, 0, N-1, b-1, c-1);
	cout << ++q << endl;
      }
    }

  }

  return 0;
  
}
