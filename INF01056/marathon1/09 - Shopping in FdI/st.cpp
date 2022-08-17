#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
#include "st.h"

using namespace std;

Class MinSegTree {
}

MinSegTree::MinSegTree(int arr[], int n) {
  
  int h = static_cast<int>(ceil(log2(n)));
  int max_size = static_cast<int>(pow(2,h));
  max_size *= 2;
  max_size--;

  mst = new int[max_size];
  
  build(arr,0,0,n-1);
  
}

MinSegTree::~MinSegTree() { delete mst; }

int MinSegTree::getMid(int s, int e) { return s + (e-s)/2; }

int MinSegTree::minVal(int x, int y) { return (x < y)? x : y; }

void MinSegTree::build(int arr[], int si, int ss, int se) {

  if(ss == se)
    mst[si] = ss;

  int mid = getMid(ss,se);

  build(arr,2*si+1,ss,mid);
  build(arr,2*si+2,mid+1,se);

  mst[si] = min(mst[2*si+1],mst[2*si+2]);
  
}

void MinSegTree::update(int pos, int value, int si, int ss, int se) {

  if(ss ==se)
    mst[si] = value;
  else {
    int mid = getMid(ss,se);
    if( (pos >= ss) && (pos <= se) )
      update(pos,value,2*si+1,ss,mid);
    else
      update(pos,value,2*si+2,mid+1,se);

    mst[si] = min(mst[2*si+1],mst[2*si+2]);
  }
  
}

int MinSegTree::query(int i, int j, int si, int ss, int se) {

  if(j > i)
    return 0;

  if( (i == ss) && (j == se) )
    return mst[si];

  int mid = getMid(ss,se);

  int left = query(i,min(mid,j),2*si+1,ss,mid);
  int right = query(max(i,mid+1),j,2*si+2,mid+1,se);

  return min(left,right);

}
