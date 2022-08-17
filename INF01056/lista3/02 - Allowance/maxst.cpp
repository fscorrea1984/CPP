#include<iostream>
#include<algorithm>
#include<string>
#include<utility>
#include<vector>
#include<cmath>
#include"maxst.h"

using namespace std;

Node::Node(pair<int,int> range, int p, int l) : I(range) , pos(p), lazy(l) { value = 0; }

Node::~Node() {}

MST::MST(const vector<int>& vi, pair<int,int> range, int p, int S) : mst(S,nullptr) {

  A = vi;
  mst[p] = new Node(range, p, 0);
  int mid = getMid(range.first,range.second);
  pair<int,int> r1(range.first,mid);
  pair<int,int> r2(mid+1,range.second);
  int L = left(mst[0]->pos);
  int R = right(mst[0]->pos);
  build(r1,L);
  build(r2,R);
  mst[p]->value = (mst[L]->value <= mst[R]->value) ? mst[L]->value : mst[R]->value;
  
}

MST::~MST() {}

int MST::getMid(int ss, int se) {
  int res = ss + (se - ss);
  res = static_cast<int>(floor(static_cast<double>(res/2.0)));
  return res;
}

int MST::parent(int p) {
  int res = (p - 1);
  res = static_cast<int>(floor(static_cast<double>(res/2.0)));
  return res;
}

int MST::left(int p) {
  int res = 2*p;
  res += 1;
  return res;
}

int MST::right(int p) {
  int res = 2*p;
  res += 2;
  return res;
}

void MST::push(int p) {
  int L = ((2*p)+1);
  int R = ((2*p)+2);
  mst[L]->value += mst[p]->lazy;
  mst[L]->lazy += mst[p]->lazy;
  mst[R]->value += mst[p]->lazy;
  mst[R]->lazy += mst[p]->lazy;
  mst[p]->lazy = 0;
}

void MST::build(pair<int,int> range, int p) {

  mst[p] = new Node(range, p, 0);
  if(range.first == range.second)
    mst[p]->value = A.at(range.first);
  else {
    int mid = getMid(range.first,range.second);
    int y = min(mid,range.second);
    pair<int,int> r1(range.first,y);
    int x = max(mid+1,range.first);
    pair<int,int> r2(x,range.second);
    int L = left(mst[p]->pos);
    int R = right(mst[p]->pos);
    build(r1,L);
    build(r2,R);
    mst[p]->value = (mst[L]->value >= mst[L]->value) ? mst[L]->value : mst[R]->value;
  }
  
}

void MST::update(pair<int,int> range, int p, int v) {

  for(int loop_index = range.first; loop_index <= range.second; loop_index++)
    A[loop_index] += v;
  
  if(range.first > range.second)
    return;
  
  if(mst[p]->I == range) {
    mst[p]->value += v;
    mst[p]->lazy += v;
  }
  else {
    push(p);
    int mid = getMid(mst[p]->I.first,mst[p]->I.second);
    pair<int,int> r1(range.first,min(mid,range.second));
    pair<int,int> r2(max(mid+1,range.first),range.second);
    int L = left(mst[p]->pos);
    int R = right(mst[p]->pos);
    update(r1,L,v);
    update(r2,R,v);
    mst[p]->value = (mst[L]->value < mst[R]->value) ?  mst[L]->value : mst[R]->value;
  }
  
}

pair<int,int> MST::query(pair<int,int> range, int p) {
  if(range.first > range.second)
    return make_pair(0,0);
  
  if(mst[p]->I == range) {
    pair<int,int> res(mst[p]->value,range.first);
    return res;
  }
  push(p);
  int mid = getMid(mst[p]->I.first,mst[p]->I.second);
  int y = (mid < range.second) ? mid : range.second;
  pair<int,int> r1(range.first,y);
  int x = (mid+1 > range.first) ? mid+1 : range.first;
  pair<int,int> r2(x,range.second);
  int L = left(mst[p]->pos);
  int R = right(mst[p]->pos);
  pair<int,int> ql = query(r1,L);
  pair<int,int> qr = query(r2,R);
  pair<int,int> res;
  if(ql.first == qr.first) {
    res = (ql < qr)? qr : ql;
    return res;
  }
  if(ql.first < qr.first) {
    res = qr;
    return res;
  }
  else {
    res = ql;
    return res;
  }
}
