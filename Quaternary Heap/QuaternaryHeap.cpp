/*-- QuaternaryHeap.cpp --*/

#include <iostream>
#include <vector>
#include "QuaternaryHeap.h"

using namespace std;

Node::Node () : id(0), key(infinite) {}
Node::~Node () {}

//private methods

bool QuaternaryHeap::root (unsigned long p) { return (p == 0); }
unsigned long QuaternaryHeap::id (unsigned long p) { return H[p].id; }
unsigned int QuaternaryHeap::key (unsigned long p) { return H[p].key; }
unsigned long QuaternaryHeap::parent (unsigned long p) { return ((p - 1) / 4); }
unsigned long QuaternaryHeap::child (unsigned long p, unsigned long c) { return ((4 * p) + c ); }

unsigned long QuaternaryHeap::num_child (unsigned long p) {

  unsigned long k = 1;
  
  if ((child(p,k)) >= length) return (0);
  
  for (k = 2; k <= 8; k++)
    if (child(p,k) == length) return (k-1);
  
}

int QuaternaryHeap::heapify_up (unsigned long p) {

  if (root(p)) return 0;

  if (key(parent(p)) > key(p)) {
    swap (pos[id(p)], pos[id(parent(p))]);
    swap (H[parent(p)], H[p]);
    heapify_up (parent(p));
  }

  return 0;
}

int QuaternaryHeap::heapify_down (unsigned long p) {

  if (num_child(p) == 0) return (0);

  unsigned long k, m = child(p,1);

  for (k = 1; k <= num_child(p); k++)
    if (key(child(p,k)) < key(m))
      m = child(p,k);

  if (key(m) < key(p)) {
    swap (pos[id(p)], pos[id(m)]);
    swap (H[m], H[p]);
    heapify_down(m); //heapify_down(p)?
  }
  
  return 0;
  
}

QuaternaryHeap::QuaternaryHeap (unsigned long par) : H(par), pos(par) {  //StartHeap-like constructor

	length = 0;

}

QuaternaryHeap::~QuaternaryHeap () {} //class destructor

unsigned long QuaternaryHeap::get_pos (unsigned long v) { return pos[v]; }

bool QuaternaryHeap::empty () { return length == 0? true : false; }

void QuaternaryHeap::insert (unsigned long v, unsigned int d) {

  Node new_element;

  new_element.id = v;
  new_element.key = d;

  H[length] = new_element;
  pos[new_element.id] = length;
  length++;
  heapify_up (length - 1);

}

void QuaternaryHeap::Delete (unsigned long p) {

  --length;

  swap (pos[id(p)], pos[id(length)]);
  swap (H[p], H[length]);

  H[length].id = 0;
  H[length].key = infinite;

  heapify_down (p);

}

Node QuaternaryHeap::get_min () {
  Node res;
  res.id = H[0].id;
  res.key = H[0].key;
  return (res);
}

Node QuaternaryHeap::delete_min () {
  Node res = get_min();
  Delete (0);
  return (res);
}

void QuaternaryHeap::update (unsigned long p, unsigned int x) {

  if (x < key(p)) {
    H[p].key = x;
    heapify_up(p);
  }
  else {
    H[p].key = x;
    heapify_down(p);
  }

}
