#include "./LinearList/DoubleLinkedList.h"

bool InitList(DNodeList& L) {
  L = new DNode();
  if (L == nullptr) {
    return false;
  }
  return true;
}

bool Empty(DNodeList& L) {
  if (L) {
    if (L->next) {
      return false;
    }
  }
  return true;
}

bool InsertNextDNode(DNode* p, DNode* s) {
  if (p == nullptr || s == nullptr) {
    return false;
  }
  s->next = p->next;
  if (p->next) {
    p->next->prior = s;
  }
  s->prior = p;
  p->next = s;
  return true;
}

bool DeleteNextDNode(DNode* p) {
  if (!p) {
    return false;
  }
  if (!p->next) {
    return false;
  }

  DNode* q = p->next;
  p->next = q->next;
  if (q->next) {
    q->next->prior = p;
  }
  delete q;
  q = nullptr;
  return true;
}

void DestoryList(DNodeList& L) {
  if (!L) return;
  while (L->next) {
    DeleteNextDNode(L);
  }
  delete L;
  L = nullptr;
  return;
}