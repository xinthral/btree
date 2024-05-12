#ifndef XNODE_H
#define XNODE_H

#include <stdio.h>

struct xNode {
  int _key;
  int _height;
  xNode* _lchild;
  xNode* _rchild;
  bool _leaf;
};

// class xDate {
// private:
//   int _day;
//   int _month;
//   int _year;

// public:
//   int getDay() { return _day; }
//   int getMonth() { return _month; }
//   int getYear() { return _year; }

//   void setDay(int day) { _day = day; }
//   void setMonth(int month) { _month = month; }
//   void setYear(int year) { _year = year; }

//   void display() {
//     printf("%d day: %d month: %d year\n", _day, _month, _year);
//   }
// };

// class xNode {
// public:
//   xDate* _key;
//   xNode* _parent;
//   xNode* _lchild;
//   xNode* _rchild;

//   xNode(xDate * inputKey) {
//     _key = inputKey;
//     _lchild = nullptr;
//     _rchild = nullptr;
//   }

//   void addKey(xDate * inputKey) { _key = inputKey; }
//   void addLeft(xNode * inputNode) { this->_lchild = inputNode; }
//   void addRight(xNode * inputNode) { this->_rchild = inputNode; }

//   xDate* getKey() { return this->_key; }
//   xNode* getLeft() { return this->_lchild; }
//   xNode* getRight() { return this->_rchild; }

//   bool hasLeft() { return this->_lchild != nullptr; }
//   bool hasRight() { return this->_lchild != nullptr; }
//   bool hasChild() { return hasLeft() || hasRight(); }

//   void display() { _key->display(); }
// };

#endif // XNODE_H //