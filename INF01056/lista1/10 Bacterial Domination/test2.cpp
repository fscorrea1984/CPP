#include <iostream>
#include <bitset>
#include <random>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int,int> Seq;

/** --- classes --- **/

class Grid {

  vector<string> row; // n rows
  vector<string> rstr; // reverse

public:

  Grid(unsigned int x) : row(x) {}
  ~Grid() {}

  void set_row(string s) { row.push_back(s); }
  string get_row(unsigned int x) { return row.at(x); }
  unsigned int size() { return (static_cast<unsigned int>(row.size())); }
  unsigned int grid_size() { return (static_cast<unsigned int>(row)); }
  void reverse_string () {

    string r;
    for(int i = 0; i < n; i++) {
      r.assign("");
      for(int j = 0; j < n; j++){
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

row | 
_________________


*/

    unsigned int count = 0;
    unsigned int perimeter = 0;
    string::iterator it;
    Seq seq;
    int pos = 0;
    int a = 0;
    int b = 0;
    vector<Seq> cur_seq;
    vector<Seq> old_seq;
    string S;
    
    //for(i = 0; i < G.size(); i++) {
    for(i = 0; i < 4; i++) { 
      S.assign(G.get_row(i));
      if(!cur_seq.empty())
	old_seq = cur_seq;
      cur_seq.clear();
      //cur_seq.erase(cur_seq.begin(),cur_seq.end());
      cur_seq.shrink_to_fit();
      pos = 0;
      for(it = S.begin(); it != S.end(); it++) {

	if(*it == '0') {
	  if(count == 0) {
	    a = pos;
	  }
	  count++;
	}
	else {
	  if(count != 0) {
	    b = a + count - 1;
	    seq = make_pair(a,b);
	    cur_seq.push_back(seq);
	    a = 0;
	    b = 0;
	    count = 0;
	  }
	  perimeter++;
	}

	pos++;
    
      }

      if(count != 0) {
	b = a + count - 1;
	seq = make_pair(a,b);
	cur_seq.push_back(seq);
	a = 0;
	b = 0;
	count = 0;
      }

      for(k = 0; k < cur_seq.size(); k++)
	cout << "Sequence " << k << ": < " << cur_seq.at(k).first << " --- " << cur_seq.at(k).second << " >" << endl;

    }

    for(k = 0; k < cur_seq.size(); k++)
      cout << "Sequence " << k << ": < " << cur_seq.at(k).first << " --- " << cur_seq.at(k).second << " >" << endl;
  
    return 0;
  
}
