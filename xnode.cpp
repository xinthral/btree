/**/
#include "xnode.h"

/**! xNode **/
/* Constructors */
template <typename T>
xNode<T>::xNode(T initialData) : xNode(initialData, -1) {}

template <typename T>
xNode<T>::xNode(T initialData, int identifier) : data(initialData), batch(identifier) {
  children = new std::vector<xNode<T>>();
}

/* Displays */
template<typename T>
void xNode<T>::showDetails() {
  printf("Node: %d\n", batch);
  printf("\t%10s:%s\n", "MaxChild", maxChildren);
  printf("\t%10s:%s\n", "Children", children.size());
}

/* Setters */
template <typename T>
int xNode<T>::setId(int identifier) { batch = identifier; return batch; }

/* Getters */
template <typename T>
int xNode<T>::getId() { return batch; }

/* Children */
template <typename T>
bool xNode<T>::hasChildren() { return (children.size() > 0); }

/* DeConstructor */
template <typename T>
xNode<T>::~xNode() {
  children.clear();
}