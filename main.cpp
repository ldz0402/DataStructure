#include <iostream>

#include "./LinearList/CircularSingleLinkedList.h"
#include "./LinearList/DoubleLinkedList.h"
#include "./LinearList/SequenceList.h"
#include "./LinearList/SingleLinkedList.h"
#include "./Queue/LinkedQueue.h"
#include "./Queue/Queue.h"
#include "./Stack/Stack.h"
#include "./utils.h"

using namespace std;
using namespace utils;

int main(int argc, char** argv) {
  LQueue<int> q;
  q.enqueue(2);
  cout << q.dequeue() << endl;
  return 0;
}
