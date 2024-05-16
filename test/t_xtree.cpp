#include "t_xtree.h"

t_xTree::t_xTree() {
  tree = new xTree(3);
  root = tree->getRoot();
  itemCount = 30;
  nodeList = new int[itemCount]{2, 0, 8, 11, 10, 5, 16, 18, 15, 14, 20, 24, 23, 28, 27, 25, 32, 33, 30, 39, 36, 42, 41, 40, 44, 47, 50, 43, 35, 19};
  int k = 0;
  for (int i = 0; i < itemCount; i++) {
    k = nodeList[i];
    root = tree->insert(root, k);
  }
}

void t_xTree::test_all() {
  t_inOrderDisplay();
}

void t_xTree::t_inOrderDisplay() {
  tree->inOrderDisplay(root); printf("\n");
}