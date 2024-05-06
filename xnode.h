#ifndef XNODE_H
#define XNODE_H

#include <stdio.h>
#include <vector>

class xNode {
private:
  bool isLeaf;
  int maxChildren;
  int data;
  int* keys;
  std::vector<xNode>* children;

public:
  /* Constructors */
  xNode();
  xNode(int initialData);
  xNode(int initialData, int identifier);

  xNode(int* initialData);
  xNode(int* initialData, int identifier);

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