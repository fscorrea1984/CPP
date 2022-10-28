#include<iostream>
#include<vector>

using namespace std;

class UDFS { //OOP style
private: vector<unsigned> p, rank; // vi p, rank; --- remember: vi is vector<int>
public:
  vector<unsigned> points;
  UDFS (unsigned);
  ~UDFS ();
  unsigned findSet(unsigned);
  bool isSameSet(unsigned,unsigned);
  void unionSet(unsigned,unsigned);
  //unsigned numDisjointSets(); // returns the number of disjoint sets currently in the structure
  //unsigned sizeOfSet(unsigned); // returns the size of set that currently contains item "i"
};
