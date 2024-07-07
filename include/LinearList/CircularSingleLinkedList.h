#ifndef __CIRCULAR_SINGLE_LINKED_LIST_H__
#define __CIRCULAR_SINGLE_LINKED_LIST_H__

typedef struct CirLNode {
  int data;
  struct CirLNode* next;

 public:
  CirLNode(int data = 0, CirLNode* next = nullptr) : data(data), next(next) {}
} CirLNode, *CirLNodeList;

bool InitList(CirLNodeList& L);

bool Empty(CirLNodeList L);

bool isTail(CirLNodeList L, CirLNode* p);

#endif