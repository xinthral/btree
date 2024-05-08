#ifndef XTREE_H
#define XTREE_H

#include "xnode.h"

class xTree {
private:
  int _size = 0;
  xNode<int>* root = NULL;

protected:
  xNode<int>* createNode(int, xNode<int>, xNode<int>, xNode<int>);
  xNode<int>* validate(xNode<int>*);

public:
  xTree(xNode<int>*);
  int size() const { return _size; }
  void displayRoot();
  ~xTree();
};

#endif // XTREE_H //


