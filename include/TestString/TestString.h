#ifndef __TEST_STRING_H__
#define __TEST_STRING_H__

#include <string>

void log(const std::string& str);

int plainFindSubstr(const std::string& source, const std::string& target);

int kmpFindSubstr(const std::string& source, const std::string& target);

int testString();

#endif