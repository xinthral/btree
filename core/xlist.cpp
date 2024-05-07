#include "xlist.h"

int xList::_error(int input) {
  return 0;
}

xList::xList(int initialSize): _size(0), _capacity(initialSize) {
  _data = new int[_capacity];
}

bool xList::isEmpty() { return _size == 0; }

int xList::capacity() { return _capacity; }

int xList::size() { return _size; }

float xList::volume() { return (float(_size) / _capacity); }

int xList::insert(int index, int input) {
  if (index < 0 || index >= _capacity) { return _error(-1); }
  _data[index] = input;
  return ++_size;
}

int xList::get(int index) {
  if (index >= _capacity) { return _error(-1); } // Make proper error handling
  return _data[index];
}

int xList::remove(int index) {
  if (index >= _capacity) { return _error(-1); } // Make proper error handling
  int output = _data[index];
  _data[index] = 0;
  return output;
}

void xList::display() {
  printf("xList: %d\n\t", _size);
  for (int i = 0; i < _size; i++) {
    if (i % 10 == 0) { printf("\n\t"); }
    printf("%d ", _data[i]);
  }
  printf("\n");
}