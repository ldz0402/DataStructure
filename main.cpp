#include <iostream>

#include "./LinearList/CircularSingleLinkedList.h"
#include "./LinearList/DoubleLinkedList.h"
#include "./LinearList/SequenceList.h"
#include "./LinearList/SingleLinkedList.h"
#include "./Queue/Queue.h"
#include "./Stack/Stack.h"
#include "./utils.h"

using namespace std;
using namespace utils;

int main(int argc, char** argv) {
  SqQueue<int> q;
  q.enqueue(2);
  auto head = q.getHead();
  cout << q.size() << endl;
  return 0;
}
