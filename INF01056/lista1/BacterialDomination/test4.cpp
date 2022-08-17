#include <iostream>
#include <bitset>
#include <random>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include "grid.h"

using namespace std;

int main(int argc,char **argv) {

  int i,j,k,m,n;
  string line = " ";

  // begin input

  // 1 - read number of grids
  
  getline(cin,line);
  m = stoi(line,nullptr,10);
  vector<Grid> grid;

  // 2 - for each grid

  for(i = 0; i < m; i++) {
    
    // read the size of the i-th grid

    getline(cin,line);
    n = stoi(line,nullptr,10);

    vector<string> v1;
    vector<string> v2;
    vector< vector<int> > v3;
    vector<int> aux(n,-1);
    
    for(j = 0; j < n; j++) {

      // read j-th line of the grid to a string
      getline(cin,line);
      stringstream str(line);
      string a,b;
      for(k = 0; k < n; k++) {
	str >> b;
	a += b;
      }

      v1.push_back(a);
      v3.push_back(aux);

    }

    string c;
    for(j = 0; j < n; j++) {
      c.assign("");
      for(k = 0; k < n; k++) {
	c += v1[k].substr(j,1);
      }
      v2.push_back(c);
    }
    
    Grid g(v1,v2,v3);
    grid.push_back(g);
    
  }

/*

row | 
_________________


*/

  int grid_index = 0;
  
  while(grid_index < m) {
    
    Grid& G = grid.at(grid_index);
    
    string S;

    n = G.size();

    int **V;
    V = new int *[10];
    for(i = 0; i < n; i++)
      V[i] = new int[10];
    for(i = 0; i < n; i++)
      for(j = 0; j < n; j++)
	V[i][j] = -1;

    // count 1s
  
    for(i = 0; i < n; i++) {
      S.assign(G.get_row(i));
      for(j = 0; j < n; j++) {
	if(S.at(j) == '1') {
	  V[i][j] = 1;
	  //G.iv[i][j] = 1;
	  G.inc_count(1);
	}
      }
    }

    // 0-sequences at left

    for(i = 0; i < n; i++) {
      S.assign(G.get_row(i));
      for(j = 0; j < n; j++) {
	//if( (S.at(j) == '0') && (G.iv[i][j] == -1) ) {
	if( (S.at(j) == '0') && (V[i][j] == -1) ) {
	  V[i][j] = 0;
	  //G.iv[i][j] = 0;
	  G.inc_count(0);
	}
	else break;
      }
    }

    // 0-sequences at right

    for(i = 0; i < n; ++i) {
      S.assign(G.get_row(i));
      for(j = n-1; j >= 0; j--) {
	//if( (S.at(j) == '0') && (G.iv[i][j] == -1) ) {
	if( (S.at(j) == '0') && (V[i][j] == -1) ) {
	  V[i][j] = 0;
	  //G.iv[i][j] = 0;
	  G.inc_count(0);
	}
	else break;
      }
    }

    // 0-sequences at left of the transverse

    for(i = 0; i < n; i++) {
      S.assign(G.get_trow(i));
      for(j = 0; j < n; j++) {
	//if( (S.at(j) == '0') && (G.iv[j][i] == -1) ) {
	if( (S.at(j) == '0') && (V[j][i] == -1) ) {
	  V[j][i] = 0;
	  G.inc_count(0);
	}
	else break;
      }
    }

    // 0-sequences at right of the transverse

    for(i = 0; i < n; i++) {
      S.assign(G.get_trow(i));
      for(j = n-1; j >= 0; j--) {
	//if( (S.at(j) == '0') && (G.iv[j][i] == -1) ) {
	if( (S.at(j) == '0') && (V[j][i] == -1) ) {
	  V[j][i] = 0;
	  //G.iv[j][i] = 0;
	  G.inc_count(0);
	}
	else break;
      }
    }
    /*
    for(i = 0; i < n; i++)
      for(j = 0; j < n; j++)
	if(G.iv[i][j] == 0)
	  G.foo(G,V,i,j);
*/
    int perimeter = G.get_count(1);
    int area = n * n;
    area -= (G.get_count(0) + G.get_count(1));
    float res = static_cast<float>(perimeter)+static_cast<float>(area);
    res /= 2.00f;

    cout.precision(2);
  
    cout << fixed << res << endl;

    ++grid_index;
    
  }

  return 0;
  
}

void foo(Grid& G,int *V[],int i,int j) {
  if(V[i][j] == -1) {
    V[i][j] = 0;
    G.inc_count(0);
  }

  string S;
  
  if(V[i][j] == 0) {
    if(i-1 >= 0) {
      S.assign(G.get_row(i-1));
      if ( (V[i-1][j] == -1) && (S.at(j) == '0') )
	foo(G,V,i-1,j);
    }

    if(i+1 < G.size()) {
      S.assign(G.get_row(i+1));
      if ( (V[i+1][j] == -1) && (S.at(j) == '0') )
	foo(G,V,i+1,j);
    }

    if(j-1 >= 0) {
      S.assign(G.get_row(i));
      if( (V[i][j-1] == -1) && (S.at(j-1) == '0') )
	foo(G,V,i,j-1);
    }

    if(j+1 < G.size()) {
      S.assign(G.get_row(i));
      if( (V[i][j+1] == -1) && (S.at(j+1) == '0') )
	foo(G,V,i,j+1);
    }
  }
}
