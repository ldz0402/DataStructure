#ifndef __STACK_H__
#define __STACK_H__

#define MaxSize 10

class SqStack {
 public:
  SqStack() : topIdx(-1) {}

 public:
  bool empty() { return this->topIdx == -1; }

  bool push(int x) {
    if (this->topIdx == MaxSize - 1) {
      return false;
    }
    ++this->topIdx;
    this->data[this->topIdx] = x;
    return true;
  }

  bool pop(int& x) {
    if (this->topIdx == -1) {
      return false;
    }
    x = this->data[this->topIdx];
    --this->topIdx;
    return true;
  }

  bool top(int& x) {
    if (this->topIdx == -1) {
      return false;
    }
    x = this->data[this->topIdx];
    return true;
  }

 private:
  int data[MaxSize];
  int topIdx;
};

#endif