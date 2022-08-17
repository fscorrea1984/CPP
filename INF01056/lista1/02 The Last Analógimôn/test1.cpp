#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <utility>

using namespace std;

int main(int argc, char **argv) {

  string line = " ", dummy;

  while(getline(cin,line)) { //begin while

    int i,j;

    pair<int,int> pos1;
    pair<int,int> pos2;

    stringstream str(line);
    int N,M;
    str >> N >> M;

    int V[N][M];

    for(i = 0; i < N; i++) { //begin for i
      getline(cin,line);
      stringstream str(line);
      for(j = 0; j < M; j++) { //begin for j
	int aux;
	str >> aux;
	V[i][j] = aux;
	
	/*if( (aux < 0) || (aux > 2) ) {
	  cerr << "Input cell is " << aux << " and should be 0, 1, or 2" << endl;
	  terminate();
	}*/

	//if(aux == 0) break;
	//if(aux == 0) continue;

	if(aux == 1) pos1 = make_pair(i,j);
	if(aux == 2) pos2 = make_pair(i,j);

      } //end for j
    } //end for i

    int drows = (pos1.first < pos2.first)? (pos2.first - pos1.first) : (pos1.first - pos2.first) ;
    int dcols = (pos1.second < pos2.second)? (pos2.second - pos1.second) : (pos1.second - pos2.second) ;
    cout << (drows + dcols) << endl;

  } //end while

  //cout << endl;

  return 0;
  
}
