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

vector<vertice> trie;

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
    if(trie[v].chave)
      return true;
  }
  return true;
}

int main() {

  while(true) {
    vector<vertice> t(1);
    int n;
    cin >> n;
    if(n == 0) break;
    trie = t;
    bool good = true;
    for(int i = 0; i < n; i++) {
      string str;
      cin >> str;
      if(search(str))
	good = false;
      else
	adiciona(str);
    }
    if(good)
      cout << "Conjunto Bom" << endl;
    else
      cout << "Conjunto Ruim" << endl;
  }

  return 0;
  
}
