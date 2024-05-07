#include <time.h>
#include <chrono>
#include <thread>
#include <stdio.h>

#include "../core/xnode.h"
#include "../core/xtree.h"
#include "../core/xlist.h"

int main(int argc, char const *argv[]) {
  /* Configurations */
  int seconds = 2;
  time_t start = time(NULL);

  /* Initializations */
  // xNode* root = new xNode(0, -1);
  // xTree tree(root);
  xList* llist = new xList(10);
  for (int i = 0; i < 10; i++) { llist->insert(i, i); }
  llist->display();

  /* Simulated Work Delay */
  std::this_thread::sleep_for(std::chrono::milliseconds(seconds * 1000));

  /* Actual Work Delay */
  llist->insert(32, -1);

  /* Respective Outputs */
  // root->showDetails();
  llist->display();
  printf("Tasks Completed: %f\n", difftime(time(NULL), start));
  return 0;
}
