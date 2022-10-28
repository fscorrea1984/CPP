#include<iostream>
#include<vector>

using namespace std;

class UDFS {

public: 
  vector<unsigned> n,c,p;
  
  UDFS(unsigned N) {
    n.assign(N,0);
    c.assign(N,0);
    p.assign(N,0);
    for(unsigned i = 0; i < N; i++) {
      c[i] = i;
      n[i] = 1;
    }
  };

  ~UDFS() {};

  unsigned findSet(unsigned i) {
    if(i != c[i])
      c[i] = findSet(c[i]);
    return c[i];
  }

  void unionSet(unsigned i, unsigned j) {
    unsigned x = findSet(i), y = findSet(j);
    if(x != y) {
      if(n[x] >= n[y]) {
        c[y] = x;
	n[x] += n[y];
	p[x] += p[y];
      }
      else {
	c[x] = y;
	n[y] += n[x];
	p[y] += p[x];
      }
    }
  };
  
};

int main(int argc, char **argv) {

  unsigned N, M;

  cin >> N >> M;

  if(N == 0 && M == 0)
    goto LEnd;

  while(true) {
    
    UDFS guilds(N);
  
    for(unsigned i = 0; i < N; i++) {
      unsigned x;
      cin >> x;
      guilds.p[i] = x;
    }

    unsigned count = 0;

    for(unsigned i = 0; i < M; i++) {
      unsigned Q,A,B;
      cin >> Q >> A >> B;
      A--;
      B--;
      if(Q == 1)
	guilds.unionSet(A,B);
      else {
	unsigned R = guilds.findSet(0);
	unsigned C = guilds.findSet(A);
	unsigned D = guilds.findSet(B);
	
	if(guilds.p[C] < guilds.p[D]) {
	  if(R == D)
	    count++;
	}
	if(guilds.p[D] < guilds.p[C]) {
	  if(R == C)
	    count++;
	}
      }
    }
  cout << count << endl;
  cin >> N >> M;
  if(N == 0 && M == 0) {
    goto LEnd;
  }
  
}
 
 LEnd:
  return 0;
  
}
