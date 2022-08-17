#include <iostream>
#include <bitset>
#include <random>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include "grid.h"

using namespace std;

Grid::Grid(vector<string> vec,vector<string> tvec,vector< vector<int> > ivec) : v(vec), tv(tvec), count(2,0), iv(ivec) {}

Grid::~Grid() {}

string Grid::get_row(int i) { return v.at(i); }

string Grid::get_trow(int i) { return tv.at(i); }

int Grid::size() { return static_cast<int>(this->v.size()); }

int Grid::get_count(int i) { return count.at(i); }

void Grid::inc_count(int i) { count[i]++; }

void Grid::print_v() {
  string::iterator it;
  for(int i = 0; i < this->v.size(); i++) {
    for(it = v[i].begin(); it < v[i].end(); it++)
      cout << *it;
    cout << endl;
    }
}

void Grid::rprint_v() {
  string::reverse_iterator rit;
  for(int i = 0; i < v.size(); i++) {
    for(rit = v[i].rbegin(); rit < v[i].rend(); rit++)
      cout << *rit;
    cout << endl;
  }
}

void Grid::print_tv() {
  string::iterator it;
  for(int i = 0; i < tv.size(); i++) {
    for(it = tv[i].begin(); it < tv[i].end(); it++)
      cout << *it;
    cout << endl;
    }
}

void Grid::rprint_tv() {
  string::reverse_iterator rit;
  for(int i = 0; i < tv.size(); i++) {
    for(rit = tv[i].rbegin(); rit < tv[i].rend(); rit++)
      cout << *rit;
    cout << endl;
  }
}

void Grid::print_iv() {
  for(int i = 0; i < iv.size(); i++)
    for(int j = 0; j < iv.size(); j++) {
      cout << iv[i][j];
      if(j+1 < iv.size())
	cout << " ";
      else
	cout << endl;
    }
}

void Grid::foo(int i,int j) {
  if(iv[i][j] == -1) {
    iv[i][j] = 0;
    count.at(0)++;
  }

  if(iv[i][j] == 0) {
    if(i-1 >= 0) {
      if ( (iv[i-1][j] == -1) && (v[i-1].at(j) == '0') )
	foo(i-1,j);
    }

    if(i+1 < v.size()) {
      if ( (iv[i+1][j] == -1) && (v[i+1].at(j) == '0') )
	foo(i+1,j);
    }

    if(j-1 >= 0) {
      if( (iv[i][j-1] == -1) && (v[i].at(j-1) == '0') )
	foo(i,j-1);
    }

    if(j+1 < v.size()) {
      if( (iv[i][j+1] == -1) && (v[i].at(j+1) == '0') )
	foo(i,j+1);
    }
  }
  
}
