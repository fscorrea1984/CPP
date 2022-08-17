#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class Grid {
  
  vector<string> v;
  vector<int> count;
  int L;

 public:
  
  Grid(vector<string> vec,int l) : v(vec), count(2,0), L(l) {};
  ~Grid() {};
  
  void scan() {

    for(int i = 0; i < L; i++)
      for(int j = 0; j < L; j++) {
	if(v.at(i).at(j) == '1')
	  count.at(1)++;
	else
	  check(i,j);
      }

  }
  
  void check(int i,int j) {

    // above

    for(int k = i; k >= 0; k--) {
      if(v.at(k).at(j) == '1')
	break;
      if(k-1 < 0)
	return;
    }

    // below

    for(int k = i; k < L; k++) {
      if(v.at(k).at(j) == '1')
	break;
      if(k+1 >= L)
	return;
    }

    // left

    for(int k = j; k >= 0; k--) {
      if(v.at(i).at(k) == '1')
	break;
      if(k-1 < 0)
	return;
    }

    // right

    for(int k = j; k < L; k++) {
      if(v.at(i).at(k) == '1')
	break;
      if(k+1 >= L)
	return;
    }

    count.at(0)++;
  
  }
  
  int getcount(int k) { return count.at(k); }
  
};

int main() {

  int Q,L;
  string line;

  getline(cin,line);
  Q = stoi(line,nullptr,10);
  vector<Grid> grid;

  for(int i = 0; i < Q; i++) {

    getline(cin,line);
    L = stoi(line,nullptr,10);

    vector<string> v;

    for(int j = 0; j < L; j++) {

      getline(cin,line);
      stringstream str(line);
      string a,b;

      for(int k = 0; k < L; k++) {
	str >> b;
	a += b;
      }

      v.push_back(a);
      
    }

    Grid g(v,L);
    grid.push_back(g);
    
  }

  int grid_index = 0;

  while(grid_index < Q) {

    Grid& G = grid.at(grid_index);

    G.scan();

    float res = static_cast<float>(G.getcount(0)) + static_cast<float>(G.getcount(1));
    res /= 2.00f;

    cout.precision(2);

    cout << fixed << res << endl;

    ++grid_index;
      
  }
  
  return 0;
  
}
