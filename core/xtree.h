#ifndef XTREE_H
#define XTREE_H

#include <stdio.h>
#include "xnode.h"

class xTree {
private:
  xNode* _root;
  int _order;

public:
  xTree(int order);

  int height(xNode* node);
  int maximum(int primary, int secondary);
  int getBalance(xNode* node);
  xNode* getRoot();
  xNode* search(int key);

  xNode* createNode(int key);
  xNode* insert(xNode* node, int key);
  void remove(int key);
  xNode* rotateRight(xNode* node);
  xNode* rotateLeft(xNode* node);

  xNode* inOrderSearch(struct xNode * node, int criteria);
  void inOrderDisplay(struct xNode * node);
};

#endif // XTREE_H //


