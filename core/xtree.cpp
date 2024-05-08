#include "xtree.h"

xTree::xTree(xNode<int>* baseNode) : root(baseNode) { }

xNode<int>* xTree::createNode(int value, xNode<int> parent, xNode<int> lchild, xNode<int> rchild) {
  return new xNode<int>(value, parent, lchild, rchild);
}

void xTree::displayRoot() {
  root->showDetails();
}
