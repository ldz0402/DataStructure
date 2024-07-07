#include "./LinearList/SingleLinkedList.h"

#include <iostream>

bool InitList(LNodeList& L) {
  L = new LNode();
  if (L == nullptr) {
    return false;
  }
  L->next = nullptr;
  return true;
}

bool Empty(LNodeList L) { return L == nullptr || L->next == nullptr; }

void display(LNodeList L) {
  if (!Empty(L)) {
    L = L->next;
    while (L) {
      printf("%d", L->data);
      if (L->next) {
        printf("->");
      }
      L = L->next;
    }
    printf("\n");
  }
  return;
}

bool InsertNextNode(LNode* p, int val) {
  if (!p) {
    return false;
  }
  LNode* s = new LNode(val);
  if (!s) {
    return false;
  }
  s->next = p->next;
  p->next = s;
  return true;
}

bool InsertPriorNode(LNode* p, int val) {
  if (!p) {
    return false;
  }
  LNode* s = new LNode(p->data, p->next);
  if (!s) {
    return false;
  }
  p->data = val;
  p->next = s;
  return true;
}

LNode* ListFind(LNodeList& L, int i) {
  if (i < 0) {
    return nullptr;
  }
  LNode* p = L;
  int j = 0;
  while (p && j < i) {
    p = p->next;
    ++j;
  }
  return p;
}

LNode* GetElem(LNodeList& L, int i) {
  if (i < 0) {
    return nullptr;
  }
  return ListFind(L, i + 1);
}

LNode* LocateElem(LNodeList& L, int val) {
  if (!L) {
    return nullptr;
  }
  if (!L->next) {
    return nullptr;
  }
  LNode* p = L->next;
  while (p) {
    if (p->data == val) {
      break;
    }
    p = p->next;
  }
  return p;
}

bool ListInsert(LNodeList& L, int i, int val) {
  return InsertNextNode(ListFind(L, i), val);
}

bool ListDelete(LNodeList& L, int i, int& del_val) {
  LNode* pre = ListFind(L, i);
  if (!pre) {
    return false;
  }
  if (!pre->next) {
    return false;
  }
  LNode* del_node = pre->next;
  del_val = del_node->data;
  pre->next = del_node->next;
  delete del_node;
  return true;
}

int Length(const LNodeList L) {
  int len = 0;
  LNode* p = L;
  while (p && p->next) {
    p = p->next;
    ++len;
  }
  return len;
}

bool ListInsertBack(LNodeList& L, int val) {
  return InsertNextNode(ListFind(L, Length(L)), val);
}

bool ListInsertFront(LNodeList& L, int val) { return InsertNextNode(L, val); }

bool ListReverse(LNodeList& L) {
  if (!L) return false;
  LNode* p = L->next;
  L->next = nullptr;

  while (p) {
    LNode* cur = p;
    p = p->next;
    cur->next = nullptr;
    ListInsertFront(L, cur->data);
  }

  return true;
}