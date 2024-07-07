#include "./LinearList/CircularSingleLinkedList.h"

bool InitList(CirLNodeList& L) {
  L = new CirLNode();
  if (!L) {
    return false;
  }
  L->next = L;
  return true;
}

bool Empty(CirLNodeList L) {
  if (!L) {
    return true;
  }
  if (L->next == L) {
    return true;
  }
  return false;
}

bool isTail(CirLNodeList L, CirLNode* p) {
  if (!p) {
    return false;
  }
  if (p->next == L) {
    return true;
  }
  return false;
}