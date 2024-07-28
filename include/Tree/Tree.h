#ifndef __TREE_H__
#define __TREE_H__

typedef struct Value {
  int val;

 public:
  Value() : val(0) {}
  Value(int val) : val(val) {}
} Value;

typedef struct TreeNode {
  Value val;
  TreeNode* left;
  TreeNode* right;

 public:
  TreeNode() : left(nullptr), right(nullptr) {}
  TreeNode(Value val) : val(val), left(nullptr), right(nullptr) {}
} TreeNode, *Tree;

Tree getTree();

void preOrder(Tree tree);
void midOrder(Tree tree);
void sufOrder(Tree tree);
void BFSOrder(Tree tree);

#endif