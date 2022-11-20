#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<limits>
#include<sstream>
#include<string>
#include<utility>
#include<vector>
#include"fheap.h"

using namespace std;

class adj {

public:

  int v;
  int w;
  adj *next;
  
  adj(int x, int y): v(x), w(y) { next = nullptr; }
  ~adj() {}
  
};

int main(int argc, char **argv) {

  int V, E;
  int v, duv, dv;
  
  int s = static_cast<int>(strtol(argv[1],nullptr,10));
  int t = static_cast<int>(strtol(argv[2],nullptr,10));

  string line = " ", dummy;

  while(line.substr(0,4) != "p sp")
    getline(cin,line);
  stringstream linestr(line);
  linestr >> dummy >> dummy >> V >> E;

  vector<adj *> adj_list(V,nullptr);
  vector<adj *> last_adj(V,nullptr);

  Heap H(V);

  --s;
  --t;

  Node *node = new Node(s,0);
  H.FibonacciHeapInsert(node);

  for(int i = 0; i < V; i++) {
    if(i != s) {
      node = new Node(i,inf);
      H.FibonacciHeapInsert(node);
    }
  }

  int j = 0;
  
  while(j < E) {
    getline(cin,line);
    if(line.substr(0,2) == "a ") {
      stringstream arc(line);
      int a,b,c;
      arc >> dummy >> a >> b >> c;
      --a;
      --b;
      if(adj_list.at(a) == nullptr) {
	adj_list.at(a) = new adj(b,c);
	last_adj.at(a) = adj_list.at(a);
      }
      else {
	last_adj.at(a)->next = new adj(b,c);
	last_adj.at(a) = last_adj.at(a)->next;
      }
    }
      ++j;
  }
    
    while(!H.isEmpty()) {
      pair<int,int> pmin = H.FibonacciHeapExtractMin();
      int u = pmin.first;
      int du = pmin.second;
      
      if(u == t) {
	if(du < inf)
	  cout << "Distance from " << s+1 << " to " << t+1 << " is of " << du << endl;
	else
	  cout << "Target destination " << t+1 << " is unreachable from " << s+1 << endl;
	return 0;
      }
      
      while(adj_list.at(u) != nullptr) {
	v = adj_list.at(u)->v;
	duv = adj_list.at(u)->w;
	dv = H.pos->at(v)->w;
	
	if((du + duv) < dv) {
	  dv = du + duv;
	  Node *aux = H.pos->at(v);
	  H.FibonacciHeapDecreaseKey(aux,dv);
	}
	adj_list.at(u) = adj_list.at(u)->next;
      }
    }

  
  return 0;
  
}
