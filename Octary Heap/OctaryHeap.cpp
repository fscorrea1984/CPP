/*-- OctaryHeap.cpp --*/

#include <iostream>
#include <vector>
#include "OctaryHeap.h"

using namespace std;

Node::Node () : id(0), key(infinite) {}
Node::~Node () {}

//private methods

bool OctaryHeap::root (unsigned long p) { return (p == 0); }
unsigned long OctaryHeap::id (unsigned long p) { return H[p].id; }
unsigned int OctaryHeap::key (unsigned long p) { return v[p].key; }
unsigned long OctaryHeap::parent (unsigned long p) { return ((p - 1) / 8); }
unsigned long OctaryHeap::child (unsigned long p, unsigned long c) { return ((8 * p) + c ); }

unsigned long OctaryHeap::num_child (unsigned long p) {

  unsigned long k = 1;
  
  if ((child(p,k)) >= length) return (0);

  for (k = 2; k <= 8; k++)
    if (child(p,k) == length) return (k-1);
  
}

int OctaryHeap::heapify_up (unsigned long p) {

  if (root(p)) return 0;

  if (key(parent(p)) > key(p)) {
    swap (pos[id(p)], pos[id(parent(p))]);
    swap (H[parent(p)], H[p]);
    heapify_up (parent(p));
  }

  return 0;
}

int OctaryHeap::heapify_down (unsigned long p) {

  if (num_child(p) == 0) return (0);

  unsigned long k, m = child(p,1);

  for (k = 1; i <= num_child(p); k++) 
    if (key(child(p,k)) < key(m))
      m = child(p,k);


  if (key(m) < key(p)) {
      swap (pos[id(p)], pos[id(m)]);
      swap (H[m], H[p]);
      heapify_down(m); //heapify_down(p)?
  }

  return 0;
    
}

OctaryHeap::OctaryHeap (unsigned long par) : v(par), pos(par) {  //StartHeap-like constructor

	length = 0;

}

OctaryHeap::~OctaryHeap () {} //class destructor

unsigned long OctaryHeap::get_pos (unsigned long v) { return pos[v]; }

bool OctaryHeap::empty () { return length == 0? true : false; }

void OctaryHeap::insert (unsigned int d) {

  Node new_element;

  new_element.id;
  new_element.key;

  H[length] = new_element;
  pos[new_element.id] = length;
  length++;
  heapify_up (length - 1);

}

void OctaryHeap::Delete (unsigned long p) {

  --length;

  swap (pos[id(p)], pos[id(length)]);
  swap (H[p], H[length]);

  H[length].id = 0;
  H[length].key = infinite;

  heapify_down (p);

}

Node OctaryHeap::get_min () {
  Node res;
  res.id = H[0].id;
  res.key = H[0].key;
  return (res);
 }

Node OctaryHeap::delete_min () {
  Node res = get_min();
  Delete (0);
  return (res);
}

void OctaryHeap::update (unsigned long p, unsigned int x) {

  if (x < key(p)) {
    v[p] = x;
    heapify_up(p);
  }
  else {
    v[p] = x;
    heapify_down(p);
  }

}
