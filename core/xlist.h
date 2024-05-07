#ifndef XLIST_H
#define XLIST_H

#include <stdio.h>

class xList {
private:
  int* _data;
  int _size;
  int _capacity;
  int _error(int);

public:
  xList(int);
  bool isEmpty();
  int capacity();
  int size();
  float volume();

  int get(int);
  int insert(int, int);
  int remove(int);

  void display();
  ~xList();  
};

#endif // XLIST_H //