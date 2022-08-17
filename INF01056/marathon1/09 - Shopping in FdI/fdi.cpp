#include <iostream>

using namespace std;

void buildmin(int stmin[], int a[], int pos, int b, int e,) {
  if(b == e)
    stmin[pos] = a[e];
  else {
    int h = (b+e)/2;
    buildmin(a, 2*pos+1, b, h);
    buildmin(a, 2*pos+2, h+1, e);
    stmax[pos] = max(stmax[2*pos+1],stmax[2*pos+2]);
  }
}

void buildmax(int stmax[], int a[], int pos, int b, int e,) {
  if(b == e)
    stmax[pos] = a[e];
  else {
    int h = (b+e)/2;
    buildmax(a, 2*pos+1, b, h);
    buildmax(a, 2*pos+2, h+1, e);
    stmax[pos] = max(stmax[2*pos+1],stmax[2*pos+2]);
  }
}

int main() {

  int N,Q;
  cin >> N;
  int a[N];
  for(int i = 0; i < N; i++)
    cin >> a[i];
  cin >> Q;
  
  int stmin[4*N];
  int stmax[4*N];

  buildmin(stmin, a, 0, 0, N-1);
  buildmax(stmax, a, 0, 0, N-1);

  for(int i = 0; i < Q; i++) {
    int a,b,c;
    cin >> a;
    cin >> b;
    cin >> c;
    if(a == 1)
      update(b, c, 0, 0, N-1);
    if(a == 2) {
      int x = query(b, c, 0, 0, N-1);
      int y = query(b, c, 0, 0, N-1);
      cout << x+y << endl;
    }
  }

}
