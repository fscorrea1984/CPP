#include <iostream>
#include <string>
#include <sstream>

using namespace std;
using uint = unsigned int;
using uchar = unsigned char;

uint board[8][8];

struct {
  int row;
  int col;
} K;

bool isLegal(int r, int c) { return ( (0 < r) && (r < 9) && (0 < c) && (c < 9) ); }

bool isDangerous(int r, int c) {
  r--;
  c--;
  if(r+1 > 6) return false;
  else {
    if (c-1 < 0) return (board[r+1][c+1] == 1);
    if (c+1 > 7) return (board[r+1][c-1] == 1);
    return ( (board[r+1][c-1] == 1) || (board[r+1][c+1] == 1) ) ;
  }
}

bool check(int row, int col) { return ( (isLegal(row,col) && !isDangerous(row,col)) ); }

void printboard() {
  for(int i = 7; i >= 0; i--)
    for(int j = 0; j < 8; j++) {
      cout << board[i][j];
      if(j == 7)
	cout << endl;
      else
	cout << " ";
    }
}

int main(int argc, char **argv) {

  int i,j,k,l,m,n;
  int Y = 1;
  string line = " ", dummy;

  while(true) {
    getline(cin,line);
    if(line == "0") break;
    stringstream str(line);
    int i1,i2;
    uchar c1,c2;
    str >> c1 >> c2;
    i1 = static_cast<int>(c1 - 0x30);
    i2 = static_cast<int>(c2 - 0x60);
    K.row = i1;
    K.col = i2;

    for(i = 0; i < 8; i++)
      for(j = 0; j < 8; j++)
	board[i][j] = 0;

    //uint count = 0;
    
    for(m = 0; m < 8; m++) {
      getline(cin,line);
      stringstream str(line);
      int i1,i2;
      uchar c1,c2;
      str >> c1 >> c2;
      i1 = static_cast<int>(c1 - 0x30);
      i2 = static_cast<int>(c2 - 0x60);
      board[i1-1][i2-1] = 1;
      board[K.row-1][K.col-1] = 5;
      //printboard();
      //cout << "---------------------------------" << endl;
    }
    uint count = 0;
    
    if(check(K.row-1,K.col-2)) count++;
    if(check(K.row-1,K.col+2)) count++;
    if(check(K.row+1,K.col-2)) count++;
    if(check(K.row+1,K.col+2)) count++;
    if(check(K.row-2,K.col-1)) count++;
    if(check(K.row-2,K.col+1)) count++;
    if(check(K.row+2,K.col-1)) count++;
    if(check(K.row+2,K.col+1)) count++;
    //cout << count << endl;
    //printboard();
    //cout << "---------------------------------" << endl;
    cout << "Caso de Teste #" << Y++ << ": " << count << " movimento(s)." << endl;;
    
  }

  return 0;
  
}
