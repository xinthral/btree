#ifndef T_XTREE_H
#define T_XTREE_H

#include "../core/xnode.h"
#include "../core/xtree.h"

class t_xTree {
private:
  xTree* tree;
  xNode* root;
  int* nodeList;
  int itemCount;
public:
  t_xTree();
  void test_all();
  void t_inOrderDisplay();
};

#endif // T_XTREE_H //