#include<iostream>
#include<utility>
#include<vector>

using namespace std;

class Node {

 public:
  
  pair<int,int> I;
  int value;
  int pos;
  int lazy;

  Node(pair<int,int>,int,int);
  ~Node();
  
};

class MST {
  
  vector<Node*> mst;
  vector<int> A;
  
  void build(pair<int,int>,int);
  int getMid(int,int);
  int parent(int);
  int left(int);
  int right(int);
  void push(int);

 public:
  MST(const vector<int>&,pair<int,int>,int,int); //arr,range,p(pos),S(vector size)
  ~MST();
  void update(pair<int,int>,int,int); //range, p = pos to be updated, v = value to update for
  pair<int,int> query(pair<int,int>,int); //range, p ---> maxv(val,idx)
  
};
