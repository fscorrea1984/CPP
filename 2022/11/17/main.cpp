#include<iostream>
#include<vector>

using namespace std;

class Bar {

	vector<int> *vint;

	public:

	Bar(int s) {
		vint = new vector<int> (s,0);
	}
	~Bar() { delete(vint); }

	int get(int pos) {
		int res = vint->at(pos);
		return res;
	}
	void set(int pos, int x) { vint->at(pos) = x; }

};

int main(int argc,char **argv) {

	Bar bar(20);

	for(int i = 0; i < 20; i++)
		cout << bar.get(i) << endl;

	for(int i = 0; i < 20; i++)
                bar.set(i,i);

	for(int i = 0; i < 20; i++)
                cout << bar.get(i) << endl;

	return 0;

}
