

#include "debug.h"
#include <iostream>
#include <vector>

int main(void) {
  int n;
  std::cin >> n;
  std::cin.ignore();

  if (n < 1) {
    std::cout << "N must be more than 0" << std::endl;
    return 1;
  }
  // find n-th prime number

    debug("Start",n);

  std::vector<int> primeN;
  primeN.reserve(n);

  primeN.push_back(2);
  primeN.push_back(3);
  for (int i = 2; i < n; ++i) {
    int currNum = primeN[i - 1] + 2;
    debug("starting currNum",currNum);
    while (true) { // find next prime until prime found
      bool prime = true;
      for (int j = 0; j < i; ++j) { // go through all porevious prime numbers
          debug("checking index ", j);
          debug("dividing by ", primeN[j]);
        if ((currNum % primeN[j]) == 0) {
          // this is not prime. move on to next number
            debug("This is not prime", "");
          currNum += 2;
          prime = false;
          break;
        }
      }
      // prime if still prime
      if (prime) {
            debug("This is prime", currNum, i);
        primeN.push_back(currNum);
        break;
      }
    }
  }

  for (auto prime : primeN) {
    std::cout << prime << std::endl;
  }

  return 0;
}
