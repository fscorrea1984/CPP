class MaxSegTree;

class MaxSegTree {

  int la; // length of a[]
  int lst; // length of segment tree t[]
  int *a; // arr[]
  int *mst; // mst[]

  int getMid(int,int);
  int maxVal(int,int);
  void build(int,int,int);
  void updateValue(int,int,int,int,int);
  int q(int,int,int,int,int);
    
 public:

  MaxSegTree(int[],int);
  ~MaxSegTree();
  void update(int,int);
  int query(int,int);
  
};
