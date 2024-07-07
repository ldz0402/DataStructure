#ifndef __SEQUENCE_H__
#define __SEQUENCE_H__

#include <cassert>

#define MaxSize 10

template <typename ElementType>
struct Sqlist {
  ElementType data[MaxSize];
  int length;

 public:
  ElementType getElem(int i) {
    assert(i >= 0 && i < length);
    return data[i];
  }

  int LocateElem(ElementType e) {
    for (int i = 0; i < length; ++i) {
      if (e == data[i]) {
        return i;
      }
    }
    return -1;
  }
};

void InitList(struct Sqlist<int>& L);

/**
 * @brief
 *
 * @param L
 * @param i [0,L.length]
 * @param e
 * @return true
 * @return false
 */
bool ListInsert(struct Sqlist<int>& L, int i, int e);

/**
 * @brief
 *
 * @param L
 * @param i [0, L.length-1]
 * @param e
 * @return true
 * @return false
 */
bool ListDelete(struct Sqlist<int>& L, int i, int& e);

#define InitSize 10

template <typename ElementType>
struct Sqlist_dyn {
  ElementType* data;
  int capacity;
  int length;

 public:
  ElementType getElem(int i) {
    assert(i >= 0 && i < length);
    return data[i];
  }

  int LocateElem(ElementType e) {
    for (int i = 0; i < length; ++i) {
      if (e == data[i]) {
        return i;
      }
    }
    return -1;
  }
};

void InitList(struct Sqlist_dyn<int>& L);

void IncreaseSize(struct Sqlist_dyn<int>& L, int len);

#endif