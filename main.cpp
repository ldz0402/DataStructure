#include <iostream>

#include "./LinearList/CircularSingleLinkedList.h"
#include "./LinearList/DoubleLinkedList.h"
#include "./LinearList/SequenceList.h"
#include "./LinearList/SingleLinkedList.h"
#include "./Queue/LinkedQueue.h"
#include "./Queue/Queue.h"
#include "./Stack/Stack.h"
#include "./Stack/StackUsage.h"
#include "./utils.h"

using namespace std;
using namespace utils;

int main(int argc, char** argv) {
  string expr = "{ 2 + 3 * 4 / 9 + ( 4 % 9) * (3 - 7) }";
  string suffix_expr = convertToSuffixExpr(expr);
  int ret = computeSuffixExpr(suffix_expr);
  cout << expr << " 's suffix expression is " << suffix_expr
       << ", and the result is " << ret << "\n\n";

  expr = "-2+3*7";
  suffix_expr = convertToSuffixExpr(expr);
  ret = computeSuffixExpr(suffix_expr);
  cout << expr << " 's suffix expression is " << suffix_expr
       << ", and the result is " << ret << "\n\n";

  expr = "+2+3*7";
  suffix_expr = convertToSuffixExpr(expr);
  ret = computeSuffixExpr(suffix_expr);
  cout << expr << " 's suffix expression is " << suffix_expr
       << ", and the result is " << ret << "\n\n";

  cout << "23 + 785*45 + 89/54*(4-8)"
       << " = " << computeExpr("23 + 785*45 + 89/54*(4-8)") << "\n\n";
  cout << "100 + 11*11"
       << " = " << computeExpr("100 + 11*11") << "\n\n";

  return 0;
}
