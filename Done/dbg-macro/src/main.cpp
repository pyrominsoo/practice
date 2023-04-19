

#include <iostream>
#include <vector>
#include "debug.h"
#include "tree.h"

int main(void) {
  std::vector<TreeNode> test;

  test.push_back(TreeNode{10});
  dstr("I just inserted TreeNode{10}");
  debug(10);
  test.push_back(TreeNode{20});

  return 0;
}
