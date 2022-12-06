#ifndef _BOARD_H_
#define _BOARD_H_

#include <vector>

template <class T>
class Board {
    public:
        Board() {
            vec.resize(NUM_SQUARE);    
        }

        void set(T item, int x, int y) {
            vec[y*BOARD_WIDTH + x] = item;
        }

        T get(int x, int y) {
            return vec.at(y*BOARD_WIDTH + x);
        }
    private:
        std::vector<T> vec;
};


class DblBoardBool {
    public:
        DblBoardBool() {
            vec.resize(NUM_SQUARE * NUM_SQUARE);
        }

        void set(bool val, int s_x, int s_y, int t_x, int t_y) {
            int index = (s_y*BOARD_WIDTH + s_x)*NUM_SQUARE + t_y*BOARD_WIDTH + t_x;
            vec[index] = val;
        }

        bool get(int s_x, int s_y, int t_x, int t_y) {
            int index = (s_y*BOARD_WIDTH + s_x)*NUM_SQUARE + t_y*BOARD_WIDTH + t_x;
            return vec[index];
        }
    private:
        std::vector<bool> vec;
};


#endif
