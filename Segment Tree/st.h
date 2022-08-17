using namespace std;

class SegTree;

class SegTree {

  int la; // length of a[]
  int lst; // length of min/max segment tree
  int *a; // arr[]
  int *minst;
  int *maxst;

  int getMid(int,int);
  int minVal(int,int);
  int maxVal(int,int);
  void build(int,int,int);
  void updateValue(int,int,int,int,int);
  int qMin(int,int,int,int,int);
  int qMax(int,int,int,int,int);
    
 public:

  SegTree(int[],int);
  ~SegTree();
  void update(int,int);
  int query(int,int);
  
};
