#include<iostream>
#include<limits>
#include<utility>
#include<vector>

using namespace std;

const int inf = std::numeric_limits<int>::max();
const int neg_inf = std::numeric_limits<int>::min();

class Heap;

class Node {

  friend class Heap;

  Node *parent;
  Node *child;
  Node *left;
  Node *right;

  bool marked;

  int degree;

 public:
  
  int v, w;
  
  Node(int,int);
  ~Node();
  
};

class Heap {

  Node *H;
  int n; // total number of nodes

 public:

  vector<Node *> *pos;
  
  Heap(int);
  ~Heap();

  pair<int,int> FibonacciHeapMinimum();
  void FibonacciHeapLink(Node *,Node *);
  void Consolidate();
  // Node * Fibonacci-Heap-Union(Node *,Node *);
  void FibonacciHeapInsert(Node *);
  pair<int,int> FibonacciHeapExtractMin();
  void FibonacciHeapDecreaseKey(Node *,int);
  void Cut(Node *,Node *);
  void CascadingCut(Node *);
  void FibonacciHeapDelete(Node *);
  void display();
  bool isEmpty();
};
