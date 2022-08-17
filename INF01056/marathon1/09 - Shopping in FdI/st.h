class MinSegTree;

class MinSegTree {

  int *mst;

 public:

  MinSegTree(int[],int);
  ~MinSegTree();
  int getMid(int,int);
  int minVal(int,int);
  void build(int[],int,int,int);
  void update(int,int,int,int,int);
  int query(int,int,int,int,int);
  
};
