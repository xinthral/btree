#include "t_xlist.h"
#include "t_xnode.h"
#include "t_xtree.h"

class xTest {
private:
  xList* list;
  xNode* node;
  xTree* tree;

public:
  xTest() { test_all(); }

  void test_all() {
    test_xlist();
    test_xnode();
    test_xtree();
  }

  void test_xlist() {
    list = new xList(10);
    list->display();
  }

  void test_xnode() {
    node = new xNode(10);
    node->showDetails();
  }

  void test_xtree() {
    tree = new xTree(node);
    tree->displayRoot();
  }
};

int main(int argc, char const *argv[]) {
  xTest* testing = new xTest();
  return 0;
}
