#include<iostream>
#include<algorithm>
#include<cstring>
#include<utility>
#include<vector>

using namespace std;

void build(int V[], int t[], int idx[], int lazy[], int v, int tl, int tr) {
  if(tl == tr) { // node is a leaf
    t[v] = V[tr]; //'maximum' is the only value
    idx[v] = tr;
    lazy[v] = 0;
  }
  else {
    int tm = (tl+tr)/2;

    build(V,t,idx,lazy,v*2+1,tl,tm);
    build(V,t,idx,lazy,v*2+2,tm+1,tr);
    lazy[v] = 0;
    t[v] = t[v*2+1] + t[v*2+2];

      /*      
    if(t[v*2+1] >= t[v*2+2]) {
      t[v] = t[v*2+1];
      idx[v] = idx[v*2+1];
    }
    else {
      t[v] = t[v*2+2];
      idx[v] = idx[v*2+2];
    }*/
  }
}

int query(int t[], int idx[], int lazy[], int v, int tl, int tr, int l, int r) {

    if(lazy[v] != 0) {
    t[v] += lazy[v];
    if(tl != tr) {
      lazy[v*2+1] += lazy[v];
      lazy[v*2+2] += lazy[v];
    }
    lazy[v] = 0;
  }

    if(tl > tr || l > r)
      return 0;

    if(l <= tl && tr <= r)
      return t[v];

    int tm = (tl+tr)/2;

    int ql = query(t,idx,lazy,v*2+1,tl,tm,l,min(r,tm));
    int qr = query(t,idx,lazy,v*2+2,tm+1,tr,max(l,tm+1),r);

    return (ql+qr);

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

      t[v] = t[v*2+1] + t[v*2+2];
      
      /*if(t[v*2+1] >= t[v*2+2]) {
	t[v] = t[v*2+1];
	idx[v] = idx[v*2+1];
      } else {
	t[v] = t[v*2+2];
	idx[v] = idx[v*2+2];
      }
      */
    }
    
  }
  
}

int main(int argc, char **argv) {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M;

  //  while(cin >> N >> M && !(N = M = 0)
  //while(cin >> N >> M)
  cin >> N >> M;

  int* V = new int[N];
  int* t = new int[4*N];
  int* idx = new int[4*N];
  int* lazy = new int[4*N];

  memset(V,0,N);
  memset(t,0,4*N);
  memset(idx,0,4*N);
  memset(lazy,0,4*N);

  build(V,t,idx,lazy,0,0,N-1);

  for(int i = 0; i < M; i++) {
    int a, b, c, d, q, x;
    int A, B;

    cin >> x;

    if(x == 1){
      cin >> a >> b;
      update(t, idx, lazy, 0, 0, N-1, a-1, a-1, b);
    }

    if(x == 2){
      c >> a >> b >> c >> d;
      if(c <= b <= d || a <= c <= b){ // there is intersection [a  [c  b]   d]
	A = min(a,c);
	B = max(b,d);
	q = query(t,idx,lazy,0,0,N-1,A,B);
	cout << q << endl;
      }
      
      if(b < c && (c - b) == 1){
	A = min(a,c);
	B = max(b,d);
	q = query(t,idx,lazy,0,0,N-1,A,B);
	cout << q << endl;
      }
      
      if(b < c && (c - b) > 1){
	int q1 = query(t,idx,lazy,0,0,N-1,a,b);
	int q2 = query(t,idx,lazy,0,0,N-1,c,d);
	cout << q1+q2 << endl;
      }
      
    }
  }

  delete[] V;
  delete[] t;
  delete[] idx;
  delete[] lazy;

  return 0;
  
}
