#include <vector>

class Grid;

class Grid {

  std::vector<std::string> v; // vector
  std::vector<std::string> tv; // transposed vector
  std::vector<int> count;

public:

  std::vector< std::vector<int> > iv; // vector of ints
  
  Grid(std::vector<std::string>,std::vector<std::string>,std::vector< std::vector<int> >);

  ~Grid();

  std::string get_row(int);
  std::string get_trow(int);
  int size();
  int get_count(int);
  void inc_count(int);
  void print_v();
  void rprint_v();
  void print_tv();
  void rprint_tv();
  void print_iv();
  void foo(int,int);

};
