#include "xlist.h"

void xList::_error_(int input) { _error = true; _e_count++; }

xList::xList(int initialSize): _size(0), _capacity(initialSize) {
  _error = false;
  _e_count = 0;
  _data = new int[_capacity]{0};
}

bool xList::isEmpty() { return _size == 0; }

int xList::capacity() { return _capacity; }

int xList::size() { return _size; }

float xList::volume() { return (float(_size) / _capacity); }

int xList::insert(int index, int input) {
  validateCapacity(index);
  if (validateIndex(index)) {
    int value = _data[index];
    bool newFlag = (value == 0);
    _data[index] = input;
    if (newFlag) { return ++_size; }
    else { return _size; }
  }
  return 0;
}

int xList::get(int index) {
  if (validateIndex(index)) { return _data[index]; }
  return 0;
}

void xList::validateCapacity(int index) {
  if (index > (_capacity - 1)) {
    int roundUp = (index * 100) / 80;
    // printf("Requesting{%d} -> Converting %d into %d\n", index, _capacity, roundUp);
    int* _newdata = new int[roundUp]{0};
    std::copy(_data, _data + _capacity, _newdata);
    delete [] _data;
    _data = _newdata;
    _capacity = roundUp;
  }
}

int xList::remove(int index) {
  if (validateIndex(index)) {
    int output = _data[index];
    _data[index] = 0;
    return output;
  }
  return 0;
}

bool xList::validateIndex(int index) {
  if (index < 0 || index >= _capacity) { _error_(-1); return false; }
  return true;
}

void xList::display() {
  printf("xList: %d", _capacity);
  for (int i = 0; i < _capacity; i++) {
    if (i % 10 == 0) { printf("\n\t"); }
    printf("%3d ", _data[i]);
  }
  printf("\n");
  if (_error) { printf("Error Count: %d\n", _e_count); }
}