class MinSegTree;

class MinSegTree {

  int la; // length of a[]
  int lst; // length of segment tree t[]
  int *a; // arr[]
  int *mst; // mst[]

  int getMid(int,int);
  int minVal(int,int);
  void build(int,int,int);
  void updateValue(int,int,int,int,int);
  int q(int,int,int,int,int);
    
 public:

  MinSegTree(int[],int);
  ~MinSegTree();
  void update(int,int);
  int query(int,int);
  
};
