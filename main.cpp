#include <iostream>

#include "./LinearList/CircularSingleLinkedList.h"
#include "./LinearList/DoubleLinkedList.h"
#include "./LinearList/SequenceList.h"
#include "./LinearList/SingleLinkedList.h"
#include "./Stack/Stack.h"
#include "./utils.h"

using namespace std;
using namespace utils;

int main(int argc, char** argv) {
  SqStack s;
  for (int i = 0; i < 10; ++i) {
    s.push(i);
  }
  int x;
  while (!s.empty()) {
    s.top(x);
    cout << x << endl;
    s.pop(x);
  }
  return 0;
}
