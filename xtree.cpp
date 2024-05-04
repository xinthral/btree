#include <time.h>
#include <chrono>
#include <thread>
#include <stdio.h>
#include "xnode.h"

int main(int argc, char const *argv[]) {
  /* code */
  time_t start = time(NULL);
  // xNode<int>* root = new xNode<int>(0);
  std::this_thread::sleep_for(std::chrono::milliseconds(5000));
  // root.showDetails();
  printf("Tasks Completed: %f\n", difftime(time(NULL), start));
  return 0;
}
