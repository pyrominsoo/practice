
#include <iostream>
#include <queue>

class BigInt {
    public:
        void insert(int digit);
        void insert_front(int digit);
        BigInt operator+(BigInt const &operand);
        void print(void);
    private:
        std::vector<int> digits;
};


void BigInt::insert(int digit) {
    digits.push_back(digit);
}

void BigInt::insert_front(int digit) {
    digits.insert(digits.begin(),digit);
};

BigInt BigInt::operator+(BigInt const &operand) {
    BigInt result;
    int carry = 0;
    for (int i = digits.size()-1; i >= 0; i--) {
        int digit_sum = digits[i] + operand.digits[i] + carry;
        if (digit_sum > 9) {
            carry = 1;        
            digit_sum -= 10;
        } else {
            carry = 0;
        }
        result.insert_front(digit_sum);
    }
    if (carry) {
        result.insert_front(1);
    }
    return result;
}

void BigInt::print(void) {
    for (auto it = digits.begin(); it != digits.end(); it++) {
        std::cout << *it ;
    }
    std::cout << std::endl;
}



/*
Algorithm:
    if only one digit,
        return the digit
    while there are at least two digits left,
        find two smallest digits from the digits
        append each to operand1 and operand2
        the order does not matter, because we're taking sum of two operands
        assign smaller digit to operand1
    if there is one left,
        append the digit to operand1
        append 0 to beginning of operand 2
    perform sum of operand1 and operand2
    output the sum

Data structure:
    heap to obtain smallest two digits

N is up to 50, so it will overflow on int.
define a class for a large int (it's an exercise)
    the class will be a vector of digits, and sum will be performed with carrys
*/


int main(void) {
    int num_testcase;
    std::cin >> num_testcase;
    while (num_testcase--) {
        int num_digit;
        int digit;
        std::cin >> num_digit;
        std::priority_queue<int,std::vector<int>,std::greater<int>> queue;
        for (int i = 0; i < num_digit; i++) {
            std::cin >> digit;
            queue.push(digit);    
        }
        if (num_digit == 1) {
            return digit;
        }

        BigInt operand1,operand2;
        while (queue.size() >= 2) {
            int digit1 = queue.top();
            queue.pop();
            int digit2 = queue.top();
            queue.pop();
            operand1.insert(digit1);
            operand2.insert(digit2);
        }
        if (queue.size() == 1) {
            int digit1 = queue.top();
            queue.pop();
            operand1.insert(digit1);
            operand2.insert_front(0);
        }
        BigInt result = operand1 + operand2;
        result.print(); 
    }
    return 0;
}
