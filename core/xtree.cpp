#include "xtree.h"

xTree::xTree(xNode* baseNode) : root(baseNode) { }

void xTree::displayRoot() {
  root->showDetails();
}
