#ifndef XTREE_H
#define XTREE_H

#include "xnode.h"

class xTree {
private:
  xNode* root;
public:
  xTree(xNode*);
  void displayRoot();
};

#endif // XTREE_H //


