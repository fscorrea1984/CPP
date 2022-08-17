#include <iostream>
#include <cmath>
#include <algorithm>
#include <utility>
#include "st.h"

using namespace std;

SegTree::SegTree(int arr[], int n) {

  la = n;
  a = new int[n];

  for(int i = 0; i < la; i++)
    a[i] = arr[i];

  int h = static_cast<int>(ceil(log2(n)));

  lst = static_cast<int>(pow(2,h));
  lst *= 2;
  lst--;

  minst = new int[lst];
  maxst = new int[lst];

  /**fill(begin(minst), end(minst), 99999);
     fill(begin(maxst), end(maxst), -1);*/

  for(int i = 0; i < lst; i++) {
    minst[i] = 99999;
    maxst[i] = -1;
  }

  build(0,la-1,0);
  
}

SegTree::~SegTree() {
  delete maxst;
  delete minst;
  delete a;
}

int SegTree::getMid(int s, int e) { return s + (e-s)/2; }

int SegTree::minVal(int x, int y) { return (x < y)? x : y; }

int SegTree::maxVal(int x, int y) { return (x > y)? x : y; }

void SegTree::build(int ss, int se, int si) {

  if(ss == se) {
    minst[si] = a[ss];
    maxst[si] = a[ss];
    return;
  }

  int mid = getMid(ss,se);
  
  build(ss,mid,2*si+1);
  build(mid+1,se,2*si+2);
  
  minst[si] = min(minst[2*si+1],minst[2*si+2]);
  maxst[si] = max(maxst[2*si+1],maxst[2*si+2]);
  
  return;
  
}

void SegTree::updateValue(int pos, int value, int ss, int se, int si) {

  if(pos < ss || pos > se) {
    cerr << "Update Error: pos = " << pos << " , ss = " << ss << " , se = " << se << endl;
    return;
  }

  if(ss == se) {
    a[pos] = value;
    minst[si] = value;
    maxst[si] = value;
  }
  else {

    int mid = getMid(ss,se);

    if(pos >= ss && pos <= mid)
      updateValue(pos,value,ss,mid,2*si+1);
    else
      updateValue(pos,value,mid+1,se,2*si+2);

    minst[si] = min(minst[2*si+1],minst[2*si+2]);
    maxst[si] = max(maxst[2*si+1],maxst[2*si+2]);
    
  }

  return;
  
}

void SegTree::update(int pos, int value) {
  updateValue(pos,value,0,la-1,0);
  return;
}

int SegTree::qMin(int qs, int qe, int ss, int se, int si) {

  if(qs <= ss && qe >= se)
    return minst[si];

  if(se < qs || ss > qe)
    return 99999;

  int mid = getMid(ss,se);

  return min(qMin(qs,qe,ss,mid,2*si+1),qMin(qs,qe,mid+1,se,2*si+2));
  
}

int SegTree::qMax(int qs, int qe, int ss, int se, int si) {

  if(qs <= ss && qe >= se)
    return maxst[si];

  if(se < qs || ss > qe)
    return -1;

  int mid = getMid(ss,se);

  return max(qMax(qs,qe,ss,mid,2*si+1),qMax(qs,qe,mid+1,se,2*si+2));
  
}

int SegTree::query(int qs, int qe) {

  if(qs < 0 || qe > la-1) {
    cerr << "Invalid query: [" << qs << "," << qe << "]" << endl;
    return -1;
  }

  if(qs > qe)
    swap(qs,qe);

  return qMax(qs,qe,0,la-1,0) - qMin(qs,qe,0,la-1,0);
  
}
