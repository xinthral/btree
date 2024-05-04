#ifndef XNODE_H
#define XNODE_H

#include <stdio.h>
#include <vector>

template <typename T>
class xNode {
private:
  bool isLeaf;
  int batch;
  int maxChildren;
  T data;
  std::vector<xNode> children;

public:
  /* Constructors */
  xNode();
  xNode(T initialData);
  xNode(T initialData, int identifier);

  /* Setters */
  int setId(int identifier);
  
  /* Getters */
  int getId();

  /* Displays */
  void showDetails();

  /* Children */
  bool hasChildren();

  /* DeConstructor */
  ~xNode();
};

#endif // XNODE_H //