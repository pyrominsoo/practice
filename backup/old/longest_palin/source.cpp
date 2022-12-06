#include <iostream>
#include <string>
#include <sstream>

void print_array(int* array, int size);

int main() {
    std::string raw_input = ""; 
    unsigned int num_testcase;

    std::getline(std::cin,raw_input);
    std::istringstream iss(raw_input);
    iss >> num_testcase;

    for (int i = 0; i < num_testcase; i++) {
        std::getline(std::cin,raw_input);
        int len_str = raw_input.length();

        int even_array[len_str-1];
        int odd_array[len_str-2];
        int max_len = 1;
        int max_len_pos = 0;

        int length = 2;
        for (int pos = 0; pos < (len_str - (length-1)); pos++) {
            if (raw_input[pos] == raw_input[pos+(length-1)]) {
                even_array[pos] = length;
                if (max_len < length) {
                    max_len = length;
                    max_len_pos = pos;
                }
            } else {
                even_array[pos] = 0;
            }
        }


        length = 3;
        for (int pos = 0; pos < (len_str - (length-1)); pos++) {
            if (raw_input[pos] == raw_input[pos+(length-1)]) {
                odd_array[pos] = length;
                if (max_len < length) {
                    max_len = length;
                    max_len_pos = pos;
                }
            } else {
                odd_array[pos] = 0;
            }
        }

        for (length = 4; length < (len_str+1); length = length + 2) {
            for (int pos = 0; pos < (len_str - (length - 1) ); pos++) {
                if (raw_input[pos] == raw_input[pos + length - 1]) {
                    if (even_array[pos+1] == (length - 2)) {
                        even_array[pos] = length;
                        if (max_len < length) {
                            max_len = length;
                            max_len_pos = pos;
                        }
                    }
                }
            }
        }


        for (length = 5; length < (len_str+1); length = length + 2) {
            for (int pos = 0; pos < (len_str - (length - 1) ); pos++) {
                if (raw_input[pos] == raw_input[pos + length - 1]) {
                    if (odd_array[pos+1] == (length - 2)) {
                        odd_array[pos] = length;
                        if (max_len < length) {
                            max_len = length;
                            max_len_pos = pos;
                        }
                    }
                }
            }
        }

        std::cout << raw_input.substr(max_len_pos,max_len) << std::endl;
    }

	return 0;
}


void print_array(int* array, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}
