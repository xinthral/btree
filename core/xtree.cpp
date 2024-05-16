#include "xtree.h"

xTree::xTree(int order) : _order(order) {
  _order = order;
  _root = nullptr;
}

int xTree::height(xNode* node) {
  if (node == nullptr) { return 0; }
  return node->_height;
}

int xTree::maximum(int primary, int secondary) {
  return (primary > secondary) ? primary : secondary;
}

int xTree::getBalance(xNode* node) {
  // Check if children exists and returns the difference
  if (node == nullptr) { return 0; }
  return height(node->_lchild) - height(node->_rchild);
}

xNode* xTree::getRoot() {
  return _root;
}

xNode* xTree::createNode(int key) {
  xNode* newNode = new xNode();
  newNode->_key = key;
  newNode->_lchild = nullptr;
  newNode->_rchild = nullptr;
  newNode->_height = 0;
  return newNode;
}

xNode* xTree::search(int key) {
  if (_root == nullptr) { return nullptr; }
  xNode * node = inOrderSearch(_root, key);
  return node;
}

xNode* xTree::insert(xNode* node, int key) {
  if (_root == nullptr) {   // If tree empty, make new node root
    // printf("Root Added: %d\n", key);
    _root = createNode(key);
    return _root;
  } else {                  // Traverse Tree for insertion

    /* 1. Perform the normal BST insertion */
    if (node == nullptr) {
      // printf("Node Empty, creating new: %d\n", key);
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
      return rotateLeft(node); 
    }
    return node;
  }
}

xNode* xTree::remove(xNode * node, int key) {
  if (node == nullptr) { return nullptr; }              // End if node empty

  /* 1. Perform the normal BST insertion */
  if (node->isLeaf()) { return (node = nullptr); }
  else {
    if (key < node->_key) {                             // Swap Left Child
      node->_lchild = remove(node->_lchild, key);
      return node;
    } else if (key > node->_key) {                      // Swap Right Child
      node->_rchild = remove(node->_rchild, key);
      return node;
    } else if (key == node->_key) {
      printf("Duplicate entry: %s\n", node->_key);
    }

    if (!node->_lchild) {
      xNode* temp = node->_lchild;
      delete node;
      return temp;
    } else if (!node->_rchild) {
      xNode* temp = node->_rchild;
      delete node;
      return temp;
    }

    xNode* parent = node;
    xNode* successor = node->_rchild;
    while (successor->_lchild) {
      parent = successor;
      successor = successor->_lchild;
    }

    node->_key = successor->_key;

    if (parent->_lchild == successor) { parent->_lchild = successor->_rchild; }
    else { parent->_rchild = successor->_rchild; }

    delete successor;
    return node;
  }
}

xNode* xTree::rotateLeft(xNode * node) {
  xNode *node1 = node->_rchild;
  // Rotate nodes
  node->_rchild = node1->_lchild;
  node1->_lchild = node;

  // Update heights
  node->_height = maximum(height(node->_lchild), height(node->_rchild)) + 1;
  node1->_height = maximum(height(node1->_lchild), height(node1->_rchild)) + 1;
  return node1;
}

xNode* xTree::rotateRight(xNode * node) {
  xNode *node1 = node->_lchild;
  // Rotate nodes
  node->_lchild = node1->_rchild;
  node1->_rchild = node;

  // Update heights
  node->_height = maximum(height(node->_lchild), height(node->_rchild)) + 1;
  node1->_height = maximum(height(node1->_lchild), height(node1->_rchild)) + 1;
  return node1;
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
    printf("%d, ", node->_key);
    inOrderDisplay(node->_rchild);
  }
}

void xTree::preOrderDisplay(struct xNode* node) {
  if (node != nullptr && node->_key > -1) {
    printf("%d, ", node->_key);
    preOrderDisplay(node->_lchild);
    preOrderDisplay(node->_rchild);
  }
}

void xTree::postOrderDisplay(struct xNode* node) {
  if (node != nullptr && node->_key > -1) {
    postOrderDisplay(node->_lchild);
    postOrderDisplay(node->_rchild);
    printf("%d, ", node->_key);
  }
}