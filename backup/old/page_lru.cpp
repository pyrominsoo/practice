#include <iostream>
#include <vector>
#include <algorithm>


void show(std::vector<int> vec) {
    std::vector<int>::iterator it;
    for (it = vec.begin(); it != vec.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}


int main(void) {
    int num_testcase;
    std::cin >> num_testcase;
    while(num_testcase--) {
        int num_page;
        std::cin >> num_page;

        int input_seq[num_page];
        for (int i = 0; i < num_page; i++) {
            std::cin >> input_seq[i];
        }
        
        int num_mem;
        std::cin >> num_mem;

        std::vector<int> lru_mm;
        std::vector<int>::iterator it;
        int page_fault = 0;
        for (int i = 0; i < num_page; i++) {
            it = find(lru_mm.begin(), lru_mm.end(), input_seq[i]);
            if ( it != lru_mm.end() ) {
                lru_mm.erase(it);
            } else {
                page_fault++;
                if (lru_mm.size() == (unsigned int)num_mem) {
                    lru_mm.erase(lru_mm.begin());
                }
            }
            lru_mm.push_back(input_seq[i]);
        }
        std::cout << page_fault << std::endl;
    }
    return 0;
}
