#include <time.h>
#include <chrono>
#include <thread>
#include <stdio.h>

#include "xnode.h"
#include "xtree.h"

int main(int argc, char const *argv[]) {
  /* code */
  int seconds = 2;
  time_t start = time(NULL);
  xNode root(0, -1);
  std::this_thread::sleep_for(std::chrono::milliseconds(seconds * 1000));
  root.showDetails();
  printf("Tasks Completed: %f\n", difftime(time(NULL), start));
  return 0;
}
