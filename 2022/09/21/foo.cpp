#include<iostream>
#include<string>

using namespace std;

int main(int argc, char *argv[]) {

  string str(argv[1]); //input "LLRLL"
  cout << str.at(2) << endl; //should output "R"

  return 0;

}
