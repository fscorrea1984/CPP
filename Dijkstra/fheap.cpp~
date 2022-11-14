#include<iostream>
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

void Heap::insert(int x, int y) {
  Node *aux = new node(x,y);
  aux->parent = aux;
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

void Heap::delete(int p) {}

void Heap::meld(Node N1, Node N2) {}

void Heap::decreasekey(int p, int x) {}

void Heap::cascadingcut(int p);

int Heap::deletemin() {}

void Heap::link(Node N1, Node N2) {}

