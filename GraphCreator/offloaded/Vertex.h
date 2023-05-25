#include <iostream>

using namespace std;

class Vertex {
 public:
  Vertex(int Label);//constructs a node
  ~Vertex();//deconstructor
  char* getLabel();//returns the integer that the vertex stores
  void setLabel(char*);
 private:
  int label;
};
