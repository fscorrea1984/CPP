#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class foo {

  int s;
  int *arr;

public:

  foo(int a[],int n) {
    s = n;
    arr = new int[n];
    for(int i = 0; i < n; i++) {
      arr[i] = a[i];
    }
  }

  ~foo() { delete arr; }
  int get(int i) { return arr[i]; }
  
};

int main() {

  int *arr;

  foo *bar;

  int N = 6;

  arr = new int[N];

  for(int i = 0; i < N; i++) {
    int line;
    cin >> line;
    arr[i] = line;
  }

  //foo bar(arr,N);
  bar = new foo(arr,N);

  delete arr;
  
  /*
  for(int i = 0; i < 5; i++)
    arr[i] = i + 70;

  for(int i = 0; i < 5; i++)
    cout << "arr [" << i << "] is = " << arr[i] << endl;

  for(int i = 0; i < N; i++)
    cout << "arr [" << i << "] is = " << arr[i] << endl;

  for(int i = 0; i < N; i++)
    cout << "bar [" << i << "] is = " << bar.get(i) << endl;
*/
  for(int i = 0; i < N; i++)
    cout << "bar [" << i << "] is = " << bar->get(i) << endl;

  //delete arr;
  delete bar;
  
  return 0;
  
}
