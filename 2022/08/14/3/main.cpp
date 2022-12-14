#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>

using namespace std;

void build(int M[], int t[], int idx[], int lazy[], int v, int tl, int tr) {
  if(tl == tr) { // node is a leaf
    t[v] = M[tr]; //'maximum' is the only value
    idx[v] = tr;
    lazy[v] = 0;
  }
  else {
    int tm = (tl+tr)/2;
    build(M,t,idx,lazy,v*2+1,tl,tm);
    build(M,t,idx,lazy,v*2+2,tm+1,tr);
    lazy[v] = 0;
    if(t[v*2+1] >= t[v*2+2]) {
      t[v] = t[v*2+1];
      idx[v] = idx[v*2+1];
    }
    else {
      t[v] = t[v*2+2];
      idx[v] = idx[v*2+2];
    }
  }
}

pair<int,int> query(int t[], int idx[], int lazy[], int v, int tl, int tr, int l, int r) {

  if(lazy[v] != 0) {
    t[v] += lazy[v];
    if(tl != tr) {
      lazy[v*2+1] += lazy[v];
      lazy[v*2+2] += lazy[v];
    }
    lazy[v] = 0;
  }

  if(tl > tr || l > r) //empty vector
    return make_pair(-1,-1);

  if(l <= tl && tr <= r)
    return make_pair(idx[v],t[v]);

  int tm = (tl+tr)/2;

  pair<int,int> ql = query(t,idx,lazy,v*2+1,tl,tm,l,min(r,tm));
  pair<int,int> qr = query(t,idx,lazy,v*2+2,tm+1,tr,max(l,tm+1),r);

  if(ql.second == qr.second)
    return (ql.first < qr.first) ? ql : qr;
  else
    return (ql.second >= qr.second) ? ql : qr;
  
}

void update(int t[], int idx[], int lazy[], int v, int tl, int tr, int l, int r, int addend) {

  if(lazy[v] != 0) {
    t[v] += lazy[v];
    if(tl != tr) {
      lazy[v*2+1] += lazy[v];
      lazy[v*2+2] += lazy[v];
    }
    lazy[v] = 0;
  }

  if(tl <= l && r <= tr && tl <= tr && l <= r) {
    if(l <= tl && tr <= r) {
      t[v] += addend;
      if(tl != tr) {
	lazy[v*2+1] += addend;
	lazy[v*2+2] += addend;
      }
    } else {
      int tm = (tl+tr)/2;

      update(t,idx,lazy,v*2+1,tl,tm,l,min(r,tm),addend);
      update(t,idx,lazy,v*2+2,tm+1,tr,max(l,tm+1),r,addend);

      if(t[v*2+1] >= t[v*2+2]) {
	t[v] = t[v*2+1];
	idx[v] = idx[v*2+1];
      } else {
	t[v] = t[v*2+2];
	idx[v] = idx[v*2+2];
      }
      
    }
    
  }
  
}

int main(int argc, char **argv) {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, Q;
  char a;
  int b, c, d;

  while(cin >> N >> Q) {

    int* M = new int[N];
    int* t = new int[4*N];
    int* idx = new int[4*N];
    int* lazy = new int[4*N];

    for(int i = 0; i < N; i++) {
      int m;

      cin >> m;
      
      M[i] = m;

      lazy[i] = 0;      
    }

    build(M,t,idx,lazy,0,0,N-1);

    for(int i = 0; i < Q; i++) {

      cin >> a;

      if(a == 'A') {
	cin >> b >> c >> d;
	update(t, idx, lazy, 0, 0, N-1, b-1, c-1, d);
      }
      
      if(a == 'C') {
	cin >> b >> c;
	cout << query(t, idx, lazy, 0, 0, N-1, b-1, c-1).first+1 << endl;
      }
      
    }

    delete[] M;
    delete[] t;
    delete[] idx;
    delete[] lazy;

  }

  return 0;
  
}
