#include <stdio.h>
#include <time.h>
#include "t_xtree.h"

class xTest {
private:
  t_xTree* tree;

public:
  xTest() { test_all(); }
  void test_all() { test_xtree(); }
  void test_xtree() { tree = new t_xTree(); }
};

int main(int argc, char const *argv[]) {
  int seconds = 2;
  time_t start = time(NULL);
  xTest* testing = new xTest();
  printf("Tasks Completed: %f\n", difftime(time(NULL), start));
  return 0;
}
