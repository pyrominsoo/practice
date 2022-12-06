#include <iostream>
#include <stdio.h>

#define debug(M, ...)

template<typename T>
class CircleArray {
    public: 
        CircleArray<T>(unsigned int cap);
        ~CircleArray<T>();
        bool insert(T new_item);
        int find(T val);
        bool remove(int index);
        unsigned int size(void);
        bool full(void);
        void pop(void);
        T &operator[](int index);
        void show(void);

    private:
        T* array;
        unsigned int cap;
        unsigned int begin;
        unsigned int end;
        bool empty;
};

template<typename T>
void swap(T& a, T& b) {
    T temp;
    temp = a;
    a = b;
    b = temp;
}


template<typename T>
CircleArray<T>::CircleArray(unsigned int cap) {
    if (cap < 2) {
        debug("cap < 2 : %d", cap);
        return;
    }
    array = new T[cap];
    this->cap = cap;
    begin = 0;
    end = 0;
    empty = true;
}

template<typename T>
CircleArray<T>::~CircleArray() {
    delete[] array;
}

template<typename T>
bool CircleArray<T>::insert(T new_item) {
    if (full()) {
        debug("CircleArray<T>::insert failed : full");
        return false;
    }

    if (empty == true) {
        empty = false;
    }

    array[end] = new_item;
    end++;
    if (end == cap) {
        end = 0;
    }

    return true;
}

template<typename T>
int CircleArray<T>::find(T val) {
    for (int i = 0; i < (int)this->size(); i++) {
        int i_ar = (begin + i) % cap;
        if (array[i_ar] == val) {
           return i; 
        }
    }
    return -1;
}

template<typename T>
bool CircleArray<T>::remove(int index) {
    if (index < 0) {
        debug("CircleArray<T>::remove received negative index %d : ", index);
        return false;
    }
    if (index >= (int)this->size()) {
        debug("CircleArray<T>::remove received invalid index %d : ", index);
        return false;
    }
    for (int i = index; i < (int)(this->size()-1); i++) {
        int i_ar = (begin + i) % cap;
        int next_ar = (i_ar + 1) % cap;
        swap<T>(array[i_ar],array[next_ar]);
    }

    if (this->size() == 1) {
        empty = true;
    }


    if (end == 0) {
        end = cap - 1;
    } else {
        end--;
    }

    return true;
}
    
template<typename T>
unsigned int CircleArray<T>::size(void) {
    unsigned int size;
    if (empty) {
        size = 0;
    } else if (end > begin) {
        size = end - begin;
    } else {
        size = (cap + end) - begin;
    }
    return size;
}


template<typename T>
bool CircleArray<T>::full(void) {
    if (this->size() == cap) {
        return true;
    } else if (this->size() > cap) {
        debug("problem at full(): size %d > cap %d", this->size(), cap);
        return false;
    } else{
        return false;
    }
}



template<typename T>
void CircleArray<T>::pop(void) {
    if (this->size() == 0) {
        debug("pop called with array empty");
        return;
    }

    if (this->size() == 1) {
        empty = true;
    }

    begin = (begin + 1) % cap;
}

template<typename T>
T &CircleArray<T>::operator[](int index) {
    int i_ar = (begin + index) % cap;
    return array[i_ar];
}

template<typename T>
void CircleArray<T>::show(void) {
    for (int i = 0; i < (int)this->size(); i++) {
        std::cout << (*this)[i] << " ";
    }
    std::cout << std::endl;
}


int main(void) {
    
    // Using array.
    // When a page is read, iterate through the array to find a match.
    //  if match is found, use swapping to bubble the element to the last position
    //  if match is not found, append to the next
    //      increment the count of page fault
    //      if full, use swapping to bubble the first element out


    // Using circular array.
    // When a page is read, iterate over the array to find a match
    //  if match is found, use swapping to bubble the element to the last position
    //  if match is not found, increment the count of page fault
    //      if not full, append to the next position
    //      if full, move the beginning of the circular buffer to the next position

    int num_testcase;
    std::cin >> num_testcase;
    while(num_testcase--) {
        int num_page;
        std::cin >> num_page;
        int input_seq[num_page];
        for (int i = 0; i < num_page; i++) {
            std::cin >> input_seq[i];
        }
        int mem_cap;
        std::cin >> mem_cap;

        CircleArray<int> lru_mm(mem_cap);
        int page_fault = 0;
        for (int i = 0; i < num_page; i++) {
            int find_res = lru_mm.find(input_seq[i]);
            debug("Handling %d", input_seq[i]);
            if (find_res >= 0) {
                debug("Found");
                lru_mm.remove(find_res);
                lru_mm.insert(input_seq[i]);
            } else {
                debug("Not Found");
                page_fault++;
                if (lru_mm.full()) {
                    debug("Full");
                    lru_mm.pop();
                }
                lru_mm.insert(input_seq[i]);
            }
        }
        std::cout << page_fault << std::endl;
    }

    return 0;
}
