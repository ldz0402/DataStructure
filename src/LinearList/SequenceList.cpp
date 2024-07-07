#include "./LinearList/SequenceList.h"

void InitList(struct Sqlist<int>& L) {
  for (int i = 0; i < MaxSize; ++i) {
    L.data[i] = 0;
  }
  L.length = 0;
  return;
}

bool ListInsert(struct Sqlist<int>& L, int i, int e) {
  if (i < 0 || i > L.length) {
    return false;
  }
  if (L.length >= MaxSize) {
    return false;
  }
  for (int j = L.length; j > i; --j) {
    L.data[j] = L.data[j - 1];
  }
  L.data[i] = e;
  L.length++;
  return true;
}

bool ListDelete(struct Sqlist<int>& L, int i, int& e) {
  if (i < 0 || i >= L.length) {
    return false;
  }
  e = L.data[i];
  for (int j = i; j < L.length - 1; ++j) {
    L.data[j] = L.data[j + 1];
  }
  L.length--;
  return true;
}

void InitList(struct Sqlist_dyn<int>& L) {
  L.data = new int[InitSize];
  for (int i = 0; i < InitSize; ++i) {
    L.data[i] = 0;
  }
  L.capacity = InitSize;
  L.length = 0;
  return;
}

void IncreaseSize(struct Sqlist_dyn<int>& L, int len) {
  int* p = L.data;
  L.data = new int[L.capacity + len];
  for (int i = 0; i < L.length; ++i) {
    L.data[i] = p[i];
  }
  L.capacity = L.capacity + len;
  delete p;
  return;
}