#ifndef XNODE_H
#define XNODE_H

class xNode {
public:
  int _key;
  xNode* _parent;
  xNode* _lchild;
  xNode* _rchild;
  xNode * newNode(int inputKey) {
    xNode * node = new xNode();
    node->_key = inputKey;

    node->_lchild = nullptr;
    node->_rchild = nullptr;
  }
  void addLeft(xNode * inputNode) { this->_lchild = inputNode; }
  void addRight(xNode * inputNode) { this->_rchild = inputNode; }
};

#endif // XNODE_H //