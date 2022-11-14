#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<limits>
#include<utility>
#include<vector>
#include"fheap.h"

using namespace std;

const int inf = std::numeric_limits<int>::max();

struct adj {
  int v;
  int w;
  adj *next;
};

int main(int argc, char **argv) {

  int V, E; // Vertices and Edges
  
  int s = static_cast<int>(strtol(argv[1],nullptr,10)); // source
  int t = static_cast<int>(strtol(argv[1],nullptr,10)); // destiny

  string line = " ", dummy;

  while(line.substr(0,4) != "p sp")
    getline(cin,line);
  stringstream linestr(line);
  linestr >> dummy >> V >> E;

  vector<adj *> adj_list(V,nullptr);
  vector<adj *> last_adj(V,nullptr);

  PriorityQueue PQ();
  
  while(int i < E) {
    getline(cin,line);
    if(line.substr(0,2) == "a ") {
      stringstream arc(line);
      int a,b,c;
      arc >> dummy >> a >> b >> c;
      if(adj_list.at(a) == nullptr) {
	adj_list.at(a) = (adj *) malloc(sizeof(adj));
	last_adj.at(a) = adj_list.at(a);
	adj_list.at(a)->v = b;
	adj_list.at(a)->w = c;
	adj_list.at(a)->next = nullptr;
      }
      else {
	last_adj.at(a)->next = (adj *) malloc(sizeof(adj));
	last_adj.at(a) = last_adj.at(a)->next;
	last_adj.at(a)->v = b;
	last_adj.at(a)->w = c;
	last_adj.at(a)->next = nullptr;
      }
      if(i == s)
	Heap H(s,0); // insert into priority queue vertex s with distance=priority of zero
      else
	H.insert(i,inf); // insert into priority queue vertex i != s with distance=priority of positive infinite;
      
      ++i;
    }
    while(!H.isEmpty()) {
      Node n = PQ.deletemin();
      int u = n.v;
      int du = n.w;
      if(u = t) {
	cout << (du < inf)? du : inf << endl;
	return 0;
      }
      while(adj_list.at(u) != nullptr) {
	v = adj_list.at(u)->v;
	duv = adj_list.at(u)->w;
	dv = PQ.p.at(v)->w;
	if((du + duv) < dv) {
	  dv = du + duv;
	  PQ.decreasekey(v,dv);
	}
	adj_list.at(v) = adj_list.at(v)->next
      }
    }
  }
  
  return 0;
  
}
