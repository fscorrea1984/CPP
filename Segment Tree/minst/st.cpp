#include <iostream>
#include <cmath>
#include <algorithm>
#include "st.h"

MinSegTree::MinSegTree(int arr[], int n) {

  la = n;
  a = new int[n];

  for(int i = 0; i < la; i++)
    a[i] = arr[i];

  int h = static_cast<int>(ceil(log2(n)));

  lst = static_cast<int>(pow(2,h));
  lst *= 2;
  lst--;

  mst = new int[lst];

  build(0,la-1,0);
  
}

MinSegTree::~MinSegTree() {
  delete mst;
  delete a;
}

void MinSegTree::getMid(int s, int e) { return s + (e-s)/2; }

void MinSegTree::minVal(int x, int y) { return (x < y)? x : y; }

void MinSegTree::build(int ss, int se, int si) {

  if(ss == se) {
    mst[si] = a[ss];
    return;
  }

  int mid = getMid(ss,se);
  
  build(ss,mid,2*si+1);
  build(mid+1,se,2*si+2);
  
  mst[si] = min(mst[2*si+1],mst[2*si+2]);
  return;
  
}

void MinSegTree::updateValue(int pos, int value, int ss, int se, int si) {

  if(pos < ss || pos > se) {
    cerr << "Update Error: pos = " << pos << " , ss = " << ss << " , se = " << se << endl;
    return;
  }

  if(ss == se) {
    a[pos] = value;
    mst[si] = value;
  }
  else {

    int mid = getMid(ss,se);

    if(pos >= ss && pos <= mid)
      updateValue(pos,value,ss,mid,2*si+1);
    else
      updateValue(pos,value,mid+1,se,2*si+2);

    mst[si] = min(mst[2*si+1],mst[2*si+2]);
    
  }

  return;
  
}

void MinSegTree::update(int pos, int value) {
  updateValue(pos,value,0,la-1,0);
  return;
}

int MinSegTree::q(int qs, int qe, int ss, int se, int si) {

  if(qs <= ss && qe >= se)
    return mst[si];

  if(se < qs || ss > qe)
    return 99999;

  int mid = getMid(ss,se);

  return min(q(qs,qe,ss,mid,2*si+1),q(qs,qe,ss,mid,2*si+2));
  
}

int MinSegTree::query(int qs, int qe) {

  if(qs < 0 || qe > la-1 || qs > qe) {
    cerr << "Invalid query: [" << qs << "," << qe << "]" << endl;
    return -1;
  }

  return q(qs,qe,0,la-1,0);
  
}
