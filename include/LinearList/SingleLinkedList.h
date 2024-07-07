#ifndef __SINGLE_LINKED_LIST_H__
#define __SINGLE_LINKED_LIST_H__

typedef struct LNode {
  int data;
  struct LNode* next;

 public:
  LNode() : data(0), next(nullptr) {}
  LNode(int data) : data(data), next(nullptr) {}
  LNode(int data, LNode* next) : data(data), next(next) {}
} LNode, *LNodeList;

bool InitList(LNodeList& L);

bool Empty(LNodeList L);

void display(LNodeList L);

bool InsertNextNode(LNode* p, int val);

bool InsertPriorNode(LNode* p, int val);

/**
 * @brief return the i-1 node
 *
 * @param L
 * @param i
 * @return LNode*
 */
LNode* ListFind(LNodeList& L, int i);

/**
 * @brief Get the i node
 *
 * @param L
 * @param i
 * @return LNode*
 */
LNode* GetElem(LNodeList& L, int i);

LNode* LocateElem(LNodeList& L, int val);

bool ListInsert(LNodeList& L, int i, int val);

bool ListDelete(LNodeList& L, int i, int& del_val);

int Length(const LNodeList L);

bool ListInsertBack(LNodeList& L, int val);

bool ListInsertFront(LNodeList& L, int val);

bool ListReverse(LNodeList& L);

#endif