#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class node {
public:
  node* v[26];
  bool endmark;
  
  node() {
    for(int i = 0; i < 26; i++)
      v[i] = nullptr;
    endmark = false;
  };

  ~node() {
    for(int i = 0; i < 26; i++)
      if(v[i] != nullptr)
	delete (v[i]);
  };
  
};

int main(int argc, char **argv) {

  int n;
  node* trie;
  while(true) {
    //a new set starts with n != 0
    cin >> n;
    if(n == 0) break;
    bool good = true; //this set is reset to "good" by default
    trie = new node();
    node* aux = trie; //aux is the auxiliary pointer, it points to trie at first
    good = true;
    //looping through this set's words
    for(int i = 0; i < n; i++) {
     
      
      string str;
      cin >> str;
      aux = trie;

      if (!good) continue; //don't process words if set is already bad

      for(char ch : str) {
	int c = ch - 'a';
	if(aux->v[c] == nullptr) {
	  aux->v[c] = new node();
	  aux = aux->v[c];
	  if(good == false) good = true;
	} //then
	else { //aux->v[c] != nullptr
	  good = false;
	  aux = aux->v[c];
	  if(aux->endmark && good == false) break;
	} //else
      } //for
      aux->endmark = true;
    } //for
    if(good)
      cout << "Conjunto Bom" << endl;
    else
      cout << "Conjunto Ruim" << endl;
    delete(trie);
  } //while

  return 0;
  
}
