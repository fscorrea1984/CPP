/*-- dijkstra.cpp --*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include "OctaryHeap.h"

using namespace std;

class Edge {

	public:

	unsigned long x;
	unsigned long y;
	unsigned int weight;

	Edge ();
	~Edge () {}	

	unsigned long get_x () { return x; }
	unsigned long get_y () { return y; }
	unsigned int get_weight () { return weight; }

	void set_x (unsigned long par) { x = par; }
	void set_y (unsigned long par) { y = par; }
	void set_weight (unsigned int par) { weight = par; }

};

Edge::Edge () : x(0), y(0), weight(0) {};

int main (int argc, char **argv) {

	unsigned long s = stoul (argv[1]);
	unsigned long t = stoul (argv[2]);
	unsigned long n = 0;
	unsigned long m = 0;
	unsigned int i = 0;

	string line = " ", dummy;
	char ac;
	unsigned long a, b;
	unsigned int c;


	// Adjusting vertices internal representation

	s--;
	t--;

	// Input Data File

	while (line.substr(0, 4) != "p sp")
		getline (cin,line);
	stringstream linestr(line);
	linestr >> dummy >> dummy >> n >> m;

	vector<unsigned long> v(n + 1, 0);
	vector<unsigned int> d(n, infinite); // d[v] = shortest distance of v from s
	vector<Edge> adj(m + 1);

	bool visited[n]; // issues when using std::vector<bool>

	for (i = 0; i < n; i++) // Old style initialization
		visited[i] = false;

	d[s] = 0;
	i = 0;

	while (i < m) {
		getline (cin, line);
		if (line.substr(0, 2) == "a ") {
			stringstream arc (line);
			arc >> ac >> a >> b >> c;
			v[a]++;
			adj[i].set_x(a - 1);
			adj[i].set_y(b - 1);
			adj[i].set_weight(c);
			i++;
		}
	}

	adj[m].set_x(n);
	i = 1;

	while (i < n) {
		v[i] += v[i - 1];
		i++;
	}

	v[n] = m;

	// Sort edges by source

	sort (adj.begin(), adj.end(), [] (const Edge & a, const Edge & b) -> bool { return a.x < b.x; } );

	// Dijkstra's Algorithm

	OctaryHeap Q(n + 1);
	Q.insert (s, d[s]);
	Pair<unsigned long, unsigned int> temp;
	Edge u;

	while (!Q.empty()) {
		temp = Q.delete_min();
		visited[temp.first] = true;
		if (temp.first == t) {
			cout << temp.second << endl;
			return 0;
		}
		for (i = v[temp.first]; i < v[(temp.first) + 1]; i++) {
			u = adj[i];
			if (visited[u.get_y()]) continue;
			if (d[u.get_y()] == infinite) {
				d[u.get_y()] = d[temp.first] + u.get_weight(); // du = dv + dvu
				Q.insert (u.get_y(), d[u.get_y()]);
			}
			else {
				d[u.get_y()] = min ((d[temp.first] + u.get_weight()), d[u.get_y()]);
				Q.update (Q.get_pos(u.get_y()), d[u.get_y()]);
			}
		}
	}

	cout << "inf" << endl;
	return 0;
}
