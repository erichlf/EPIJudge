#include <memory>
#include "binary_tree_node.h"
#include "test_framework/generic_test.h"
#include <limits>

using std::unique_ptr;

bool IsBinaryTreeBST(const unique_ptr<BinaryTreeNode<int>>& tree) {
  return isBST(tree, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
}

bool isBST(const unique_ptr<BinaryTreeNode<int>>& tree, min, max) {
  if (tree == nullptr) return true;
  else if (tree->data < min || tree->data > max) return false;

  return isBST(tree->left, min, tree->data) &&
         isBST(tree->right, tree->data, max);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"tree"};
  return GenericTestMain(args, "is_tree_a_bst.cc", "is_tree_a_bst.tsv",
                         &IsBinaryTreeBST, DefaultComparator{}, param_names);
}
