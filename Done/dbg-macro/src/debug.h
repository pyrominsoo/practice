#ifndef DEBUG_MACRO_H
#define DEBUG_MACRO_H

#ifdef NDEBUG
#define debug(...)
#define dstr(...)
#else
#include <iostream>
#define debug(...) logger(#__VA_ARGS__, __VA_ARGS__)
template <typename... Args>
void logger(std::string vars, Args &&...values) {
  std::cout << vars << " = ";
  std::string delim = "";
  (..., (std::cout << delim << values, delim = ", "));
  std::cout << std::endl;
}
#define dstr(x) [](std::string str){ std::cout << str << "\n"; }(x)
#endif

#endif // DEBUG_MACRO_H
