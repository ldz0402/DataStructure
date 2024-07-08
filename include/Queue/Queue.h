#ifndef __QUEUE_H__
#define __QUEUE_H__

#define MaxSize 10

template <class ElementType>
class SqQueue {
 public:
  SqQueue() : front(0), rear(0) {}

 public:
  bool empty() { return this->front == this->rear; }

  bool enqueue(ElementType x) {
    if ((this->rear + 1) % MaxSize == this->front) {
      return false;
    }
    this->data[this->rear] = x;
    this->rear = (this->rear + 1) % MaxSize;
    return true;
  }

  bool dequeue(ElementType& x) {
    if (empty()) {
      return false;
    }
    x = this->data[this->front];
    this->front = (this->front + 1) % MaxSize;
    return true;
  }

  ElementType getHead() {
    assert(!empty() && "The queue is empty!");
    return this->data[this->front];
  }

  int size() { return (this->rear + MaxSize - this->front) % MaxSize; }

 private:
  ElementType data[MaxSize];
  int front, rear;
};

#endif