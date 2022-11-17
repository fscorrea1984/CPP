#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<limits>
#include<utility>
#include<vector>

using namespace std;

class FHeap;

class Node {

  friend class FHeap;

  int v; // vertex number associated to edge
  int w; // weight/distance
  
  Node *parent;
  Node *left;
  Node *right;
  Node *child;
  
  bool marked;
  int degree;

public:
  
  Node(int,int);
  ~Node();
  
};

class FHeap {

  Node *H = nullptr;
  Node *T = nullptr;
  Node *minroot = nullptr;
  int maxdegree;
  vector<Node *> *pos;

public:

  Heap(int);
  ~Heap();
  bool isEmpty();
  void insert(int,int);
  int getmin();
  void deleteH(int);
  void meld(Node *,Node *);
  void decreasekey(int,int);
  void cascadingcut(int);
  pair<int,int> deletemin();
  void link(Node *,Node *);
};

