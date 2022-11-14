#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<limits>
#include<utility>
#include<vector>
#include"fheap.h"

using namespace std;

Node::Node(int x, int y) : v(x), w(y) {}

Node::~Node() {}

Heap::Heap(int x, int y, int z): V(z) {
  H = new Node(x,y);
  p.at(x) = H;
  H->parent = H;
  H->left = H;
  H->right = H;
  T = H;
  minroot = H;
}

Heap::~Heap() {}

bool Heap::isEmpty {
  return (H = nullptr)? true : false;
}

void Heap::insert(int x, int y) {
  Node *aux = new node(x,y);
  aux->parent = aux;
  // meld (T,aux)
  aux->left = T;
  aux->right = T->right;
  aux->right->left = aux;
  T->right = aux;
  T = aux;
  if(minroot->w > aux->w)
    minroot = aux;
  p.at(x) = aux;
}

int Heap::getmin() { return minroot->w; }

void Heap::delete(int p) {
  int x = std::numeric_limits<int>::min();
    decreasekey(p,x);
    deletemin();
}

void Heap::meld(Node *N1, Node *N2) {
  N1->right->left = N2->left;
  N2->left->right = N1->right;
  N2->left = N1;
  N1->right = N2;
}

void Heap::decreasekey(int p, int x) {
  p.at(p)->w = x;
  Node *aux = p.at(p);
  if(x < minroot->w)
    minroot = aux;
  if(aux->parent != aux) {
    if(aux->parent->w > aux->w) {
      Node *P = aux->parent;
      aux->marked = false;
      aux->parent = aux;
      aux->left = aux;
      aux->right = aux;
      aux->child = aux;
      meld(T,aux);
      P->degree--;
      cascadingcut(P)
    }
  }
}

void Heap::cascadingcut(Node *p) {
  if(p->parent = p)
    return;
  if(p->marked == false)
    p->marked = true;
  else {
    Node *P = p->parent;
      p->marked = false;
      p->parent = p;
      p->left = p;
      p->right = p;
      aux->child = p;
      meld(T,p);
      P->degree--;
      cascadingcut(P)
  }
}

pair<int,int> Heap::deletemin() {
  if(H == minroot)
    H = H->right;
  if(T == minroot)
    T = T->left;
  Node * h2 = minroot->child;
  minroot-> = nullptr;
  meld(T,h2);
  vector<Node *> A(maxdegree, nullptr);
  Node *temp = H;
  do {
  if(A.at(temp->degree) == nullptr)
    A.at(temp->degree) = temp;
  else
    link(A.at(temp->degree),temp);
  temp = temp->right;
  } while(temp != H);
  int a = minroot->v;
  int b = minroot->w;
  Node *p_min = minroot;
  minroot = H;
  delete(p_min);
  Node *M = H;
  do {
    minroot = (minroot->w < M->w)? minroot : M;
    M = M->right;
  } while(M != H)
  return make_pair(a,b);
}

void Heap::link(Node* N1, Node* N2) {
  if(N1->w < N2->w) {
    if(N1->child = N1) {
      N1->child = N2;
      N2->parent = N1;
      N1->degree++;
    }
    else {
      N1->degree++;
      N2->parent = N1;
      Node *aux = N1->child;
      meld(aux,N2);
    }
  }
  else {
    if(N2->child = N2) {
      N2->child = N1;
      N1->parent = N2;
      N2->degree++;
    }
    else {
      N2->degree++;
      N1->parent = N2;
      Node *aux = N2->child;
      meld(aux,N1);
    }
  }
}

