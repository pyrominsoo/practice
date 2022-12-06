#include <iostream>

class Count_one {
    public:
        Count_one(bool** grid, int n, int m) {
            this->grid = grid;
            this->n = n;
            this->m = m;
            count_table = new int*[n];
            for (int i = 0; i < n; i++) {
                count_table[i] = new int[m];
            }
        }
        ~Count_one() {
            for (int i = 0; i < n; i++) {
                delete [] count_table[i];
            }
            delete [] count_table;
        }
        int count_to_coord(int x1, int y1);
        void init_count_table();
        void print_count_table();
    private:
        bool** grid;
        int n;
        int m;
        int** count_table;
};

int Count_one::count_to_coord(int x1, int y1) {
    if (x1 < 0 || y1 << 0 || y1 > (n-1) || x1 > (m-1)) {
        throw;
    }
  
    return count_table[y1][x1];
};

void Count_one::init_count_table(void) {
    count_table[0][0] = (grid[0][0] == true)? 1 : 0;
    for (int col = 1; col < m; col++) {
        count_table[0][col] = (grid[0][col] == true)? (count_table[0][col-1] + 1) : (count_table[0][col-1]);
    }
    for (int row = 1; row < n; row++) {
        count_table[row][0] = (grid[row][0] == true)? (count_table[row-1][0] + 1) : (count_table[row-1][0]);
    }
    for (int row = 1; row < n; row++) {
        for (int col = 1; col < m; col++) {
            int count_row = 0;
            for (int i = 0; i < col; i++) {
                if (grid[row][i] == true) {
                    count_row++;
                } 
            }
            int count_col = 0;
            for (int j = 0; j < row; j++) {
                if (grid[j][col] == true) {
                    count_col++;
                }
            }
            count_table[row][col] = count_table[row-1][col-1] + count_row + count_col;
        }
    }
}

void Count_one::print_count_table(void) {
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            std::cout << count_table[row][col] << "\t";
        }
        std::cout << std::endl;
    }
}


int main(void) {
    int n = 10;
    int m = 12;
    bool** grid = new bool*[n];
    for (int i = 0; i < n; i++) {
        grid[i] = new bool[m];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            grid[i][j] = ((i+j)%2 == 0)? true : false;
        }
    }
    Count_one test(grid, 10, 12);
    test.init_count_table();
    test.print_count_table();
    return 0;
}
