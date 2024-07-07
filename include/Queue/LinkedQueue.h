#ifndef __LINKED_QUEUE_H__
#define __LINKED_QUEUE_H__

template <class ElementType>
class LQueue {
 private:
  struct Node {
    ElementType data;
    Node* next;
  };

 public:
  LQueue() : front(nullptr), rear(nullptr) {}

 public:
  bool empty() { return front == nullptr; }

  void enqueue(ElementType x) {
    Node* s = new Node();
    s->data = x;
    s->next = nullptr;
    if (empty()) {
      front = rear = s;
    } else {
      rear->next = s;
      rear = s;
    }
    return;
  }

  ElementType dequeue() {
    assert(!empty() && "The queue is empty!");

    Node* p = front;
    ElementType ret = p->data;
    front = p->next;
    if (rear == p) {
      front = rear = nullptr;
    }
    delete p;
    return ret;
  }

 private:
  Node *front, *rear;
};

#endif