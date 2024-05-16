#include <chrono>
#include <thread>
#include <time.h>
#include <stdio.h>

#include "../core/xnode.h"
#include "../core/xtree.h"

int main(int argc, char const *argv[]) {
  /* Configurations */
  int seconds = 2;
  int maximum = 50;
  time_t start = time(NULL);
  std::srand(start);

  /* Initializations */
  xTree* tree = new xTree(3);
  xNode* root = tree->getRoot();

  /* Simulated Work Delay */
  // std::this_thread::sleep_for(std::chrono::milliseconds(seconds * 1000));

  /* Actual Work Delay */
  int step = 0;
  root = tree->insert(root, 0);
  for (int i = 0; i < maximum; i++) {
    step = (std::rand() % maximum) + 1;
    root = tree->insert(root, step);
  }

  /* Respective Outputs */
  printf("Displaying inOrder:\n");
  tree->inOrderDisplay(root);
  printf("\n");

  printf("Displaying preOrder:\n");
  tree->preOrderDisplay(root);
  printf("\n");

  printf("Displaying postOrder:\n");
  tree->postOrderDisplay(root);
  printf("\n");

  printf("Tasks Completed: %f\n", difftime(time(NULL), start));
  return 0;
}
