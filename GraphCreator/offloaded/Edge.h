#include <iostream>
#include <Vertex.h>

using namespace std;

class Edge {
 public:
  Edge(int Weight, Vertex* First, Vertex* Second);
  ~Edge();
  int getWeight();
  void setWeight(int);
  void setFirst(Vertex*);
  void setSecond(Vertex*);
  Vertex* getFirst();
  Vertex* getSecond();
  Vertex* getOtherEnd(Vertex* v);
 private:
  int weight;
  Vertex* first;
  Vertex* second;
};
