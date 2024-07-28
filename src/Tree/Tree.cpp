#include "./Tree/Tree.h"

#include <iostream>
#include <queue>

using namespace std;

Tree getTree() {
  Tree tree = new TreeNode(1);
  tree->left = new TreeNode(2);
  tree->right = new TreeNode(3);
  tree->left->left = new TreeNode(4);
  tree->left->right = new TreeNode(5);
  tree->right->left = new TreeNode(6);
  tree->right->right = new TreeNode(7);
  return tree;
}

void preOrder(Tree tree) {
  if (!tree) {
    return;
  }
  printf("%d ", tree->val.val);
  preOrder(tree->left);
  preOrder(tree->right);
  return;
}

void midOrder(Tree tree) {
  if (!tree) {
    return;
  }
  midOrder(tree->left);
  printf("%d ", tree->val.val);
  midOrder(tree->right);
  return;
}

void sufOrder(Tree tree) {
  if (!tree) {
    return;
  }
  sufOrder(tree->left);
  sufOrder(tree->right);
  printf("%d ", tree->val.val);
  return;
}

void BFSOrder(Tree tree) {
  if (!tree) {
    return;
  }
  queue<TreeNode*> q;
  q.push(tree);
  while (!q.empty()) {
    size_t len = q.size();
    for (size_t i = 0; i < len; ++i) {
      TreeNode* node = q.front();
      q.pop();
      printf("%d ", node->val.val);
      if (node->left) {
        q.push(node->left);
      }
      if (node->right) {
        q.push(node->right);
      }
    }
  }
  printf("\n");
  return;
}