#ifndef XNODE_H
#define XNODE_H

#include <stdio.h>
#include <string>
#include <typeinfo>
#include <vector>

template <typename T>
class xNode {
private:
  T _data;
  xNode<T>* _parent;
  xNode<T>* _leftChild;
  xNode<T>* _rightChild;

public:
  /* Constructors */
  xNode() : xNode(0) {}
  xNode(T initialData) : _data(initialData) {}
  xNode(T initialData, xNode<T> parent, xNode<T> leftChild, xNode<T> rightChild) {
    setElement(initialData);
    setParent(parent);
    setLeftChild(leftChild);
    setRightChild(rightChild);
  }

  /* Getters */
  T getElement() const { return _data; }
  xNode<T>* getParent() const { return _parent; }
  xNode<T>* getLeftChild() const { return _leftChild; }
  xNode<T>* getRightChild() const { return _rightChild; }

  /* Setters */
  void setElement(T element) { _data = element; }
  void setParent(xNode<T> node) { _parent = &node; }
  void setLeftChild(xNode<T> node) { _leftChild = &node; }
  void setRightChild(xNode<T> node) { _rightChild = &node; }

  /* Displays */
  void showDetails() {
    printf("Type: %s\n", typeid(_data).name());
    if (typeid(_data) == typeid(int)) {
      printf("Node: %d\n", _data);
      printf("  Parent    : %p\n", _parent);
      printf("  LeftChild : %p\n", _leftChild);
      printf("  RightChild: %p\n", _rightChild);
    }
  }
};

#endif // XNODE_H //