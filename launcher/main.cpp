#include <chrono>
#include <thread>
#include <time.h>
#include <stdio.h>

#include "../core/xnode.h"
#include "../core/xtree.h"

int main(int argc, char const *argv[]) {
  /* Configurations */
  int seconds = 2;
  time_t start = time(NULL);

  /* Initializations */
  xTree* tree = new xTree();
  xNode* root = new xNode();

  /* Simulated Work Delay */
  std::this_thread::sleep_for(std::chrono::milliseconds(seconds * 1000));

  /* Actual Work Delay */
  // llist->insert(32, -1);

  /* Respective Outputs */
  tree->displayRoot();
  printf("Tasks Completed: %f\n", difftime(time(NULL), start));
  return 0;
}
