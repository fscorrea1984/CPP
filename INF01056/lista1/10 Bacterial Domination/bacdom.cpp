#include <iostream>
#include <bitset>
#include <random>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

/* -- global declaration space -- */

int main(int argc,char **argv) {

  string line = " ", dummy;

  // begin input

  // 1 - read number of grids
  
  getline(cin,line);
  unsigned int n(line);
  vector<unsigned int> size(n);// size.at(0) == 8 ; size.at(0) == 9

  // 2 - for each grid

  for(unsigned int i = 0; i < n; i++) {
    
    // read the size of the i-th grid

    getline(cin,line);
    size
    
    

  }

  // end input

  return 0;
  
}
