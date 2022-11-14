#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<limits>
#include<utility>
#include<vector>

using namespace std;

class Node {

  static count = 0;
  int id;
  int v; // vertex number associated to edge
  int w; // weight/distance
  Node *parent;
  Node *left;
  Node *right;
  Node *child;
  bool visited = false;
  bool marked = false;
  int degree = 0;

public:
  
  Node::Node(int v, int w);
  Node::~Node();
  
};

class Heap {

  int V;
  Node *H = nullptr;
  Node *T = nullptr;
  vector<Node *> p(V,nullptr);
  Node *minroot = nullptr;
  int maxdegree;

public:

  Heap::Heap(int v, int w);
  Heap::~Heap();
  bool isEmpty();
  void insert(int v, int w);
  int getmin();
  void delete(int p);
  void meld(Node N1, Node N2);
  void decreasekey(int p, int x);
  void cascadingcut(int p);
  int deletemin();
  void link(Node N1, Node N2);
};

