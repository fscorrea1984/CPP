#include <iostream>
#include <bitset>
#include <random>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

/** --- classes --- **/

class Grid {

  //unsigned int n;
  vector<string> row; // n rows
  vector<string> rstr; // reverse

public:

  Grid() {}
  //Grid(unsigned int x) : n(x) {}
  ~Grid() {}

  void set_row(string s) { row.push_back(s); }
  string get_row(unsigned int x) { return row.at(x); }
  string get_rstr(unsigned int x) { return rstr.at(x); }
  unsigned int size() { return (static_cast<unsigned int>(row.size())); }
  // unsigned int grid_size() { return (static_cast<unsigned int>(row)); }
  void reverse_string () {

    string r;
    for(int i = 0; i < row.size() ; i++) {
      r.assign("");
      for(int j = 0; j < row.size(); j++){
	r += row[j].substr(i,1);
      }
      rstr.push_back(r);
    }

  }
  
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

  string S;
  string::iterator it;
  string::reverse_iterator rit;
  unsigned int gs = G.size();
  
  for(unsigned int i = 0; i < gs; i++){
    S.assign(G.get_row(i));
    for(it = S.begin(); it < S.end(); it++)
      cout << *it;
    cout << endl;
  }

  cout << endl;

  for(unsigned int i = 0; i < gs; i++){
    S.assign(G.get_row(i));
    for(rit = S.rbegin(); rit < S.rend(); rit++)
      cout << *rit;
    cout << endl;
  }

  cout << endl;
  
  for(unsigned int i = 0; i < gs; i++) {
    S.assign(G.get_rstr(i));
    for(it = S.begin(); it < S.end(); it++)
      cout << *it;
    cout << endl;
  }

  cout << endl;
  
  for(unsigned int i = 0; i < gs; i++) {
    S.assign(G.get_rstr(i));
    for(rit = S.rbegin(); rit < S.rend(); rit++)
      cout << *rit;
    cout << endl;
  }

}

int main(int argc,char **argv) {

  unsigned int i,j,k;
  unsigned int m,n;
  string line = " ", dummy;

  // begin input

  // 1 - read number of grids
  
  getline(cin,line);
  m = (static_cast<unsigned int>(stoi(line,nullptr,10)));
  vector<Grid> grid;

  // 2 - for each grid

  for(unsigned int i = 0; i < m; i++) {
    
    // read the size of the i-th grid

    getline(cin,line);
    n = static_cast<unsigned int>(stoi(line,nullptr,10));
    Grid g;
    grid.push_back(g);

    for(unsigned int j = 0; j < n; j++) {

      // read j-th line of the grid to a string
      getline(cin,line);
      stringstream str(line);
      string b;
      for(int k = 0; k < n; k++) {
	str >> dummy;
	b += dummy;
      }

      //cout << b << endl;
      grid.at(i).set_row(b);

    }

  }

  for(i = 0; i < m; i++)
    grid.at(i).reverse_string();
    
  // end input

  //print1(grid,n);

  //print2(grid.at(0));
  //print2(grid.at(1));

  // which grid is being processed
  Grid& G = grid.at(2);

/*

row | 
_________________


*/

  unsigned int count = 0;
  unsigned int perimeter = 0;
  unsigned int c0 = 0;
  unsigned int c1 = 0;

  string::iterator it;
  string::reverse_iterator rit;
  int pos = 0;
  string S;

  unsigned int gs = G.size();
  unsigned int* pint = new unsigned int(gs);
  gs = (*pint) * (*pint);
  vector<vector<bool> > q(*pint,vector<bool>(*pint,false));

  // count 1s
  
  for(i = 0; i < G.size(); i++) {
    S.assign(G.get_row(i));
    for(it = S.begin(); it < S.end(); it++) {
      if(*it == '1') {
	c1++;
	perimeter++;
      }
    }
  }
  
  // 0-sequences at left

  for(i = 0; i < G.size(); i++) {
    S.assign(G.get_row(i));
    for(j = 0; j < G.size(); j++) {
      if( (S.at(j) == '0') && (!q[i][j]) ) {
	c0++;
	q[i][j] = true;
      }
      else break;
    }
  }

  // 0-sequences at right

  for(i = 0; i < G.size(); i++) {
    S.assign(G.get_row(i));
    for(j = G.size()-1; j < 0-1; j--) {
      if( (S.at(j) == '0') && (!q[i][j]) ) {
	c0++;
	q[i][j] = true;
      }
      else break;
    }
  }

  vector<vector<bool> > qr(*pint,vector<bool>(*pint,false));
  for(i = 0; i < *pint; i++)
    for(j = 0; j < *pint; j++)
      qr[i][j] = q[j][i];
  

  
  // 0-sequences at left of the transverse

  for(i = 0; i < G.size(); i++) {
    S.assign(G.get_rstr(i));
    for(j = 0; j < G.size(); j++) {
      if( (S.at(j) == '0') && (!qr[i][j]) ) {
	c0++;
	qr[i][j] = true;
      }
      else break;
    }
  }

  // 0-sequences at right of the transverse

  for(i = 0; i < G.size(); i++) {
    S.assign(G.get_rstr(i));
    for(j = G.size()-1; j < 0-1; j--) {
      if( (S.at(j) == '0') && (!qr[i][j]) ) {
	c0++;
	qr[i][j] = true;
      }
      else break;
    }
  }

  for(i = 0; i < *pint; i++)
    for(j = 0; j < *pint; j++)
      if(q[i][j] != qr[i][j])
	q[i][j] = qr[i][j] = true;

  delete(pint);

  perimeter = c1;
  int area = gs-(c0+c1);
  float res = static_cast<float>(perimeter)+static_cast<float>(area);
  res /= 2.00f;

  cout.precision(2);
  
  cout << fixed << res << endl;

  return 0;
  
  }
