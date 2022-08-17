/*-- QuaternaryHeap.h --*/

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int infinite = numeric_limits<int>::max();

class Node {

	public:

  unsigned long id;
  unsigned int key;

  Node ();
  ~Node ();

};

class QuaternaryHeap {

	//basic vectors: H and pos

	vector<Node> H;
	unsigned long length;

	vector<unsigned long> pos; // pos[v] = position of v in Q

	//Heap-related methods

	bool root (unsigned long);
	unsigned long id (unsigned long);
	unsigned int key (unsigned long);
	
	unsigned long parent (unsigned long);
	unsigned long child (unsigned long, unsigned long); // parameter varies from 1 to d (in this case, from 1 to 4)
	unsigned long num_child (unsigned long);

	int heapify_up (unsigned long);
	int heapify_down (unsigned long);

	public:

	//constructor & destructor

	QuaternaryHeap (unsigned long par);
	~QuaternaryHeap ();

	//PriorityQueue-related methods

	bool empty ();

	void insert (unsigned long, unsigned int);
	void Delete (unsigned long);
	Node get_min ();
	Node delete_min ();
	void update (unsigned long, unsigned int);

	//pos methods

	unsigned long get_pos (unsigned long);

};
