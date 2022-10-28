#include<iostream>
#include<vector>
#include"UDFS.h"

using namespace std;

UDFS::UDFS(unsigned N) {
  rank.assign(N,0);
  p.assign(N,0);
  points.assign(N,0);
  for(unsigned i = 0; i < N; i++)
    p.at(i) = i; // p[i] = i;
}

UDFS::~UDFS() {}

unsigned UDFS::findSet(unsigned i) { return (p.at(i) == i)? i : (p.at(i) = findSet(p.at(i))); }

bool UDFS::isSameSet(unsigned i, unsigned j) { return findSet(i) == findSet(j); }

void UDFS::unionSet(unsigned i, unsigned j) {
  if(!isSameSet(i,j)) { // if from different set
    unsigned x = findSet(i), y = findSet(j);
    if(rank.at(x) > rank.at(y)) {
      p.at(y) = x; // rank keeps the tree short
      points.at(x) += points.at(y);
    }
    else {
      p.at(x) = y;
      points.at(y) += points.at(x);
      if(rank.at(x) == rank.at(y))
	rank.at(y)++;	      
    }
  }
}

/*
int UDFS::numDisjointSets() {}

int UDFS::sizeOfSet(int i) {}
*/
