#include <iostream>

int main() {
   
    int num_val;
    std::cin >> num_val;
  
    int sum = 0;
    int num_entered = 0;

    while (num_val--) {
        int new_val;
        std::cin >> new_val;
        sum += new_val;
        num_entered++;
        int mean = sum / num_entered;
        std::cout << mean << std::endl;
    }

    return 0;
}
