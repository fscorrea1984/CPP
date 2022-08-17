#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct vertice {

  int arcos[27];
  bool chave = false;

  vertice() {
    fill(begin(arcos), end(arcos), -1);
  }
  
};

vector<vertice> trie(1);

void adiciona(string const& s) {
  int v = 0;
  for(char ch : s) {
    int c = ch - 'a';
    if(trie[v].arcos[c] == -1) {
      trie[v].arcos[c] = trie.size();
      trie.emplace_back();
    }
    v = trie[v].arcos[c];
  }
  trie[v].chave = true;
}

bool search(string const& s) {
  int v = 0;
  for(char ch : s) {
    int c = ch - 'a';
    if(trie[v].arcos[c] == -1) {
      return false;
    }
    v = trie[v].arcos[c];
  }
  return trie[v].chave;
}

int main(int argc, char **argv) {

  string str1 = "ana";
  string str2 = "anedota";
  string str3 = "anaconda";
  string str4 = "vaca";
  string str5 = "vaquinha";

  adiciona(str1);
  adiciona(str2);
  adiciona(str3);
  adiciona(str4);
  adiciona(str5);

  if(argc != 2) {
    cerr << "Usage: a.out string_to_search" << endl;
    terminate();
  }
  
  string str(argv[1]);

  if(search(str))
    cout << str << " found" << endl;
  else
    cout << str << " not found" << endl;
  
  return 0;
  
}
