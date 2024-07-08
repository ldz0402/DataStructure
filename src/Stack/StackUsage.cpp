#include "./Stack/StackUsage.h"

#include <map>
#include <stack>

using namespace std;

bool compareOperator(char op1, char op2) {
  if (op1 == '+' || op1 == '-') {
    return true;
  } else if (op2 == '*' || op2 == '/' || op2 == '%') {
    return true;
  }
  return false;
}

int compute(int x, int y, char c) {
  switch (c) {
    case '+':
      return x + y;
    case '-':
      return x - y;
    case '*':
      return x * y;
    case '/':
      return x / y;
    default:
      return x % y;
  }
}

string convertToSuffixExpr(string expr) {
  string ret = "";
  stack<char> operators;
  static map<char, char> bracket = {{')', '('}, {']', '['}, {'}', '{'}};

  for (auto c : expr) {
    if (c == ' ') {
      continue;
    }
    switch (c) {
      case '+':
      case '-':
      case '*':
      case '/':
      case '%': {
        while (!operators.empty()) {
          if (operators.top() == '(' || operators.top() == '[' ||
              operators.top() == '{') {
            break;
          }
          if (compareOperator(c, operators.top())) {
            ret += operators.top();
            operators.pop();
          } else {
            break;
          }
        }
        operators.push(c);
        break;
      }
      case '(':
      case '[':
      case '{': {
        operators.push(c);
        break;
      }
      case ')':
      case ']':
      case '}': {
        while (!operators.empty()) {
          if (operators.top() != bracket[c]) {
            ret += operators.top();
            operators.pop();
          } else {
            operators.pop();
            break;
          }
        }
        break;
      }
      default: {
        ret += c;
        break;
      }
    }
  }

  while (!operators.empty()) {
    ret += operators.top();
    operators.pop();
  }
  return ret;
}

int computeSuffixExpr(string suffix_expr) {
  int ret = 0;
  stack<int> nums;
  nums.push(0);

  for (auto c : suffix_expr) {
    switch (c) {
      case '+':
      case '-':
      case '*':
      case '/':
      case '%': {
        int num1 = nums.top();
        nums.pop();
        nums.top() = compute(nums.top(), num1, c);
        break;
      }
      default: {
        nums.push(c - '0');
        break;
      }
    }
  }
  return nums.top();
}

int computeExpr(std::string expr) {
  static map<char, char> bracket = {{')', '('}, {']', '['}, {'}', '{'}};
  stack<int> nums;
  nums.push(0);
  stack<char> ops;
  for (int i = 0; i < expr.size(); ++i) {
    if (expr[i] == ' ') {
      continue;
    }
    if (expr[i] >= '0' && expr[i] <= '9') {
      string num = "";
      num += expr[i];
      while (i + 1 < expr.size() && expr[i + 1] >= '0' && expr[i + 1] <= '9') {
        num += expr[++i];
      }
      nums.push(atoi(num.c_str()));
    } else {
      char c = expr[i];
      switch (c) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '%': {
          while (!ops.empty()) {
            if (ops.top() == '(' || ops.top() == '[' || ops.top() == '{') {
              break;
            }
            if (compareOperator(c, ops.top())) {
              int num1 = nums.top();
              nums.pop();
              nums.top() = compute(nums.top(), num1, ops.top());
              ops.pop();
            } else {
              break;
            }
          }
          ops.push(c);
          break;
        }
        case '(':
        case '[':
        case '{': {
          ops.push(c);
          break;
        }
        case ')':
        case ']':
        case '}': {
          while (!ops.empty()) {
            if (ops.top() != bracket[c]) {
              int num1 = nums.top();
              nums.pop();
              nums.top() = compute(nums.top(), num1, ops.top());
              ops.pop();
            } else {
              ops.pop();
              break;
            }
          }
          break;
        }
      }
    }
  }

  while (!ops.empty()) {
    int num1 = nums.top();
    nums.pop();
    nums.top() = compute(nums.top(), num1, ops.top());
    ops.pop();
  }
  return nums.top();
  // return computeSuffixExpr(convertToSuffixExpr(expr));
}
