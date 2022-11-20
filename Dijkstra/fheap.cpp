#include<iostream>
#include<cmath>
#include<limits>
#include<utility>
#include<vector>
#include"fheap.h"

using namespace std;

Node::Node(int a, int b): v(a), w(b) {
  parent = nullptr;
  child = nullptr;
  left = this;
  right = this;
  marked = false;
  degree = 0;
}

Node::~Node() {}

Heap::Heap(int V) {
  H = nullptr;
  pos = new vector<Node *>(V,nullptr);
  n = 0;
}

Heap::~Heap() { delete(pos); }

pair<int,int> Heap::FibonacciHeapMinimum() { return make_pair(H->v,H->w); }

void Heap::FibonacciHeapLink(Node *y,Node *x) {
  (y->left)->right = y->right;
   (y->right)->left = y->left;

   if(x->right == x)
     H = x;
   
  y->left = y;
  y->right = y;
  y->parent = x;

  if(x->child == nullptr)
    x->child = y;
  
    y->right = x->child;
    y->left = (x->child)->left;
    ((x->child)->left)->right = y;
    (x->child)->left = y;

    if(y->w < (x->child)->w)
      x->child = y;

    x->degree++;    
}

void Heap::Consolidate() {
  int d;
  double dd = log(n)/log(2);
  int Dn = static_cast<int>(dd);
  vector<Node *> A(Dn+1,nullptr);

  Node *n1 = H;
  Node *n2;
  Node *n3;
  Node *n4 = n1;

  do {
    n4 = n4->right;
    d = n1->degree;

    while(A.at(d) != nullptr) {
      n2 = A.at(d);

      if(n1->w > n2->w) {
	n3 = n1;
	n1 = n2;
	n2 = n3;
      }
      
      if(n2 == H)
	H = n1;
      
      FibonacciHeapLink(n2,n1);
      
      if(n1->right == n1)
	H = n1;
      
      A.at(d) = nullptr;
      d++;
    }
    A.at(d) = n1;
    n1 = n1->right;
  } while(n1 != H);
  
  H = nullptr;
  
  for(int i = 0; i <= Dn; i++) {
    if(A.at(i) != nullptr) {
      A.at(i)->left = A.at(i);
      A.at(i)->right = A.at(i);

      if(H != nullptr) {
	(H->left)->right = A.at(i);
	A.at(i)->right = H;
	A.at(i)->left = H->left;
	H->left = A.at(i);
	
	if(A.at(i)->w < H->w)
	  H = A.at(i);
      }
      else 
	H = A.at(i);
      
      if( (H == nullptr) || (A.at(i)->w < H->w) )
	H = A.at(i);
    }
  }
}

// Node * Heap::Fibonacci-Heap-Union(Node *N1,Node *N2) {}

void Heap::FibonacciHeapInsert(Node *x) {
  if(H == nullptr)
    H = x;

  else {
  (H->left)->right = x;
  x->left = H->left;
  H->left = x;
  x->right = H;
  }

  if(x->w < H->w)
    H = x;

  ++n;

  pos->at(x->v) = x;
}

pair<int,int> Heap::FibonacciHeapExtractMin() {
  Node *z = H;
  Node *x = nullptr;
  Node *aux = z;
  pos->at(z->v) = nullptr;
  pair<int,int> res = make_pair(z->v,z->w);

  if(z->child != nullptr) {
    x = z->child;
    do {
      aux = x->right;

      (H->left)->right = x;
      x->right = H;
      x->left = H->left;
      H->left = x;

      if(x->w < H->w)
	H = x;

      x->parent = nullptr;
      x = aux;
    } while(aux != z->child);
  }



  
  (z->left)->right = z->right;
  (z->right)->left = z->left;
  H = z->right;

  if( (z == z->right) && (z->child == nullptr) )
    H = nullptr;
  else {
    H = z->right;
    Consolidate();
  }

  --n;
  
  delete(z);
  
  return res;
}

void Heap::FibonacciHeapDecreaseKey(Node *x, int k) {
  x->w = k;

  Node *y = x->parent;

  if( (y != nullptr) && (x->w < y->w) ) {
    Cut(x,y);
    CascadingCut(y);
  }

  if(x->w < H->w)
    H = x;
}

void Heap::Cut(Node *y,Node *x) {
  if(y == y->right)
    x->child = nullptr;

  (y->left)->right = y->right;
  (y->right)->left = y->left;

  if(y == x->child)
    x->child = y->right;

  x->degree--;

  y->right = y;
  y->left = y;
  (H->left)->right = y;
  y->right = H;
  y->left = H->left;
  H->left = y;
  
  y->parent = nullptr;
  y->marked = false;
}

void Heap::CascadingCut(Node *y) {
  Node *z = y->parent;

  if(z != nullptr) {
    if(y->marked == false)
      y->marked = true;
    else {
      Cut(y,z);
      CascadingCut(z);
    }
  }
}

void Heap::FibonacciHeapDelete(Node *x) {
  FibonacciHeapDecreaseKey(x,neg_inf);
  FibonacciHeapExtractMin();
}

void Heap::display() {
  Node *aux = H;

  if(aux == nullptr)
    cout << "The Heap is Empty" << endl;
  else {
    cout << "The root nodes of Heap are: " << endl;

    do {
      cout << "<" << aux->v << "," << aux->w << ">" << endl;

      aux = aux->right;

      if(aux != H)
	cout << "--->";

    } while( (aux != H) && (aux->right != nullptr) );

    cout << endl
	 << "The heap has " << n << " nodes" << endl
	 << endl;
  }
}

bool Heap::isEmpty() {
  return (H == nullptr)? true : false;
}
