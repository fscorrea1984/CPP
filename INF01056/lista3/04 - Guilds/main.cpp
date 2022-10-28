#include<iostream>
#include<vector>
#include"UDFS.h"

using namespace std;

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
      guilds.points.at(i) = x;
    }

    unsigned count = 0;

    for(unsigned i = 0; i < M; i++) {
      unsigned Q,A,B;
      cin >> Q >> A >> B;
      if(Q == 1)
	guilds.unionSet(A-1,B-1);
      else {
	unsigned R = guilds.findSet(0);
	unsigned C = guilds.findSet(A-1);
	unsigned D = guilds.findSet(B-1);
	
	if(guilds.points.at(C) < guilds.points.at(D)) {
	  if(guilds.isSameSet(R,D))
	  count++;
	}
	if(guilds.points.at(D) < guilds.points.at(C)) {
	  if(guilds.isSameSet(R,C))
	  count++;
	}
      }
    }

    cin >> N >> M;
    if(N == 0 && M == 0) {
      cout << count << endl;
      goto LEnd;
    }
  
  }
 
 LEnd:
  return 0;
  
}
