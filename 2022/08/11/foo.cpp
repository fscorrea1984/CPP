#include<iostream>
#include<string>
#include<vector>

using namespace std;

class MST {

  vector<int> mst;

public:
  MST(int n) : mst(n,-1) {}
  ~MST() {}
  void print() {
    for(vector<int>::iterator it = mst.begin(); it != mst.end(); ++it)
      cout << *it << endl;
  }
};

int main(int argc, char **argv) {

  MST segtree(15);
  segtree.print();
  return 0;

}
