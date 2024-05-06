/**/
#include "xnode.h"

/**! xNode **/
/* Constructors */
xNode::xNode(int initialData, int identifier) : data(initialData) {
  children = new std::vector<xNode>();
}

xNode::xNode(int initialData) : xNode(initialData, -1) {}

/* Displays */
void xNode::showDetails() {
  printf("Node: %d\n", data);
  printf("\t%10s:%s\n", "MaxChild", maxChildren);
  printf("\t%10s:%s\n", "Children", children->size());
}

/* Setters */
int xNode::setId(int identifier) { data = identifier; return data; }

/* Getters */
int xNode::getId() { return data; }

/* Children */
bool xNode::hasChildren() { return (children->size() > 0); }

/* DeConstructor */
xNode::~xNode() {
  children->clear();
}