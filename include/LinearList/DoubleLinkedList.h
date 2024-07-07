#ifndef __DOUBLE_LINKED_LIST_H__
#define __DOUBLE_LINKED_LIST_H__

typedef struct DNode {
  int data;
  DNode* prior;
  DNode* next;

 public:
  DNode(int data = 0, DNode* prior = nullptr, DNode* next = nullptr)
      : data(data), prior(prior), next(next) {}
} DNode, *DNodeList;

bool InitList(DNodeList& L);

bool Empty(DNodeList& L);

bool InsertNextDNode(DNode* p, DNode* s);

bool DeleteNextDNode(DNode* p);

void DestoryList(DNodeList& L);

#endif