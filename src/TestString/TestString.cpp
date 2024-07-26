#include "./TestString/TestString.h"

#include <algorithm>
#include <iomanip>
#include <iostream>

using namespace std;

void log(const string& str) {
  size_t len = str.length();
  size_t size = str.size();
  size_t max_size = str.max_size();
  size_t capacity = str.capacity();
  cout << std::right << setw(10) << "str: " << str << endl;
  cout << std::right << setw(10) << "length: " << len << endl;
  cout << std::right << setw(10) << "size: " << size << endl;
  cout << std::right << setw(10) << "max_size: " << max_size << endl;
  cout << std::right << setw(10) << "capacity: " << capacity << endl;
  cout << "\n";
  return;
}

int plainFindSubstr(const string& source, const string& target) {
  int len_s = source.length();
  int len_t = target.length();
  int i = 0, j = 0;
  while (i < len_s && j < len_t) {
    if (source[i] == target[j]) {
      ++i;
      ++j;
    } else {
      i = i - j + 1;
      j = 0;
    }
  }
  if (j == len_t) {
    return i - j;
  }
  return -1;
}

void computeNextArray(const string& str, int*& next) {
  size_t len = str.length();
  for (int i = 0; i < len; ++i) {
    if (i == 0) {
      next[i] = -1;
    } else if (i == 1) {
      next[i] = 0;
    } else {
      string up = str.substr(1, i - 1);
      string down = str.substr(0, i - 1);
      while (up != down) {
        up.erase(up.begin());
        down.pop_back();
      }
      next[i] = up.size();
    }
  }

  {  // optimize
    for (int i = 2; i < len; ++i) {
      if (str[next[i]] == str[i]) {
        next[i] = next[next[i]];
      }
    }
  }
  return;
}

int kmpFindSubstr(const string& source, const string& target) {
  int len_s = source.length();
  int len_t = target.length();
  int* next = new int[len_t];
  computeNextArray(target, next);

  int i = 0, j = 0;
  bool flag = false;
  while (i < len_s && j < len_t) {
    if (j == -1 || source[i] == target[j]) {
      ++i;
      ++j;
    } else {
      j = next[j];
    }
  }

  if (j == len_t) {
    return i - j;
  }

  return -1;
}

int testString() {
  string str = "hello,world!";
  log(str);
  str.resize(5);

  string str2 = "what's your name?";
  swap(str, str2);
  log(str);

  str.clear();
  log(str);

  str.shrink_to_fit();
  log(str);

  str = "hello,world!";
  size_t pos = str.find("ld");

  cout << std::right << setw(10) << "pos: " << plainFindSubstr("12345", "12")
       << "\n";
  cout << std::right << setw(10) << "pos: " << plainFindSubstr("12345", "8")
       << "\n";
  cout << std::right << setw(10)
       << "pos: " << kmpFindSubstr("googlogoogoogle", "aaaab") << "\n";
  return 0;
}