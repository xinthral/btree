#include "xtree.h"

xTree::xTree(int order) : _order(order) {
  _order = order;
  _root = nullptr;
}

xNode* xTree::createNode(int key) {
  xNode* newNode = new xNode();
  newNode->_key = key;
  newNode->_lchild = nullptr;
  newNode->_rchild = nullptr;
  newNode->_height = -1;
  return newNode;
}

xNode* xTree::getRoot() {
  return _root;
}

xNode* xTree::insert(xNode* node, int key) {
  if (_root == nullptr) {   // If tree empty, make new node root
    printf("Root Added: %d\n", key);
    _root = createNode(key);
    return _root;
  } else {                  // Traverse Tree for insertion

    /* 1. Perform the normal BST insertion */
    if (node == nullptr) {
      printf("Node Empty, creating new: %d\n", key);
      return createNode(key);
    }
    if (key < node->_key) { node->_lchild = insert(node->_lchild, key); } 
    else if (key > node->_key) { node->_rchild = insert(node->_rchild, key); } 
    else { return node; }

    /* 2. Update height of this ancestor node */
    node->_height = 1 + maximum(height(node->_lchild), height(node->_rchild));

    /* 3. Get the balance factor of this ancestor node to check whether this node 
          became unbalanced */
    int balance = getBalance(node);

    /* 4. Handle unbalanced conditions */
    // LL Case
    if (balance > 1 && key < node->_lchild->_key) { 
      return rotateRight(node);
    }
    // RR Case
    if (balance < -1 && key > node->_rchild->_key) { 
      return rotateLeft(node);
    }
    // LR Case
    if (balance > 1 && key > node->_lchild->_key) {
      node->_lchild = rotateLeft(node->_lchild);
      return rotateRight(node); 
    }
    // RL Case
    if (balance < -1 && key < node->_rchild->_key) {
      node->_rchild = rotateRight(node->_rchild);
      return rotateRight(node); 
    }

    return node;
  }
}

void xTree::remove(int key) {
  // Search for key in tree
  xNode* node = search(key);
  if (node == nullptr) { return; }
  // Delete key from node
}

xNode* xTree::search(int key) {
  if (_root == nullptr) { return nullptr; }
  xNode * node = inOrderSearch(_root, key);
  return node;
}

xNode* xTree::inOrderSearch(struct xNode* node, int criteria) {
  if (node == nullptr) { return node; }
  inOrderSearch(node->_lchild, criteria);
  if (node->_key == criteria) { return node; }
  inOrderSearch(node->_rchild, criteria);
}

void xTree::inOrderDisplay(struct xNode * node) {
  if (node != nullptr && node->_key > -1) {
    inOrderDisplay(node->_lchild);
    printf("%d ", node->_key);
    inOrderDisplay(node->_rchild);
  }
}

int xTree::height(xNode* node) {
  if (node == nullptr) { return 0; }
  return node->_height;
}

int xTree::maximum(int primary, int secondary) {
  return (primary > secondary) ? primary : secondary;
}

int xTree::getBalance(xNode* node) {
  if (node == nullptr) { return 0; }
  return height(node->_lchild) - height(node->_rchild);
}

xNode* xTree::rotateLeft(xNode * node) {
  xNode *node1 = node->_lchild;
  xNode *node2 = node->_rchild;
  
  // Rotate nodes
  node1->_lchild = node;
  node->_rchild = node2;
  
  // Update heights
  node->_height = maximum(height(node->_lchild), height(node->_rchild)) + 1;
  node1->_height = maximum(height(node1->_lchild), height(node1->_rchild)) + 1;
  return node1;
}

xNode* xTree::rotateRight(xNode * node) {
  xNode *node1 = node->_lchild;
  xNode *node2 = node->_rchild;

  // Rotate nodes
  node1->_rchild = node;
  node->_lchild = node2;

  // Update heights
  node->_height = maximum(height(node->_lchild), height(node->_rchild)) + 1;
  node1->_height = maximum(height(node1->_lchild), height(node1->_rchild)) + 1;
  return node1;
}