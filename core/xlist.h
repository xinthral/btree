#ifndef XLIST_H
#define XLIST_H

// #include <array>
#include <algorithm>
#include <stdio.h>
// #include <string.h>

class xList {
private:
  bool _error;
  int _e_count;
  void _error_(int);

  int* _data;
  int _size;
  int _capacity;

public:
  xList(int);
  bool isEmpty();
  int capacity();
  int size();
  float volume();

  int get(int);
  int insert(int, int);
  int remove(int);
  bool validateIndex(int);
  void validateCapacity(int);

  void display();
  ~xList();  
};

#endif // XLIST_H //