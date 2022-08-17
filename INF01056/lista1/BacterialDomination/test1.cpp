#include <iostream>
#include <bitset>
#include <random>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

/** --- classes --- **/

class Grid {

  unsigned int n; // dimensions of a grid nxn
  vector<string> row; // n rows

public:

  Grid(unsigned int x) : n(x) {}
  ~Grid() {}

  void set_row(string s) { row.push_back(s); }
  string get_row(unsigned int x) { return row.at(x); }
  unsigned int size() { return (static_cast<unsigned int>(row.size())); }
  unsigned int grid_size() { return (static_cast<unsigned int>(n)); }
  
};

/** --- functions --- **/

void print1(vector<Grid>& vg,unsigned int n) {

  for(unsigned int i = 0; i < n; i++) {
    Grid& G = vg.at(i);
    unsigned int gs = G.size();
    for(unsigned int j = 0; j < gs; j++)
      cout << G.get_row(j) << endl;
  }
  
}

void print2(Grid& G) {
  
  unsigned int gs = G.size();
  for(unsigned int i = 0; i < gs; i++)
    cout << G.get_row(i) << endl;

}

int main(int argc,char **argv) {

  unsigned int i,j,k;
  unsigned int gs;
  string line = " ", dummy;

  // begin input

  // 1 - read number of grids
  
  getline(cin,line);
  unsigned int n(static_cast<unsigned int>(stoi(line,nullptr,10)));
  //vector<unsigned int> size(n);// size.at(0) == 8 ; size.at(0) == 9
  vector<Grid> grid;

  // 2 - for each grid

  for(unsigned int i = 0; i < n; i++) {
    
    // read the size of the i-th grid

    getline(cin,line);
    gs = static_cast<unsigned int>(stoi(line,nullptr,10));
    Grid g(gs);
    grid.push_back(g);

    for(unsigned int j = 0; j < gs; j++) {

      // read j-th line of the grid to a string
      getline(cin,line);
      stringstream str(line);
      string b;
      for(int k = 0; k < gs; k++) {
	str >> dummy;
	b += dummy;
      }

      //cout << b << endl;
      grid.at(i).set_row(b);

    }

  }

  // end input

  //print1(grid,n);

  //print2(grid.at(0));
  //print2(grid.at(1));

  // what grid is being processed
  Grid& G = grid.at(0);

/*

ZERO-SEQUENCES VECTOR:

row | 
_________________


*/
  
  return 0;
  
}
