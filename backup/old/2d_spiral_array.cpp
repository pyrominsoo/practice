#include <iostream>

#ifdef NDEBUG
#define debug(M, ...)
#else
#include <stdio.h>
#define debug(M, ...) fprintf(stderr, "DEBUG %s:%d: " M "\n",\
        __FILE__, __LINE__, ##__VA_ARGS__)
#endif

int** spiral(int n) {
    int val = 1;
    int num_steps = n;
    int dir = 0;
    static const int x_val[4] = {1, 0, -1, 0};
    static const int y_val[4] = {0, 1, 0, -1};
    int** answer = new int*[n];
    for (int i = 0; i < n; i++) {
        answer[i] = new int[n];
    }
    int x_pos = -1;
    int y_pos = 0;
 
    while (num_steps > 0) {
        for (int i = 0; i < num_steps; i++) {
            int x_chg = x_val[dir];
            int y_chg = y_val[dir];
            x_pos += x_chg;
            y_pos += y_chg;
            debug("Wrote %d to (%d,%d)", val, x_pos, y_pos);
            answer[y_pos][x_pos] = val;
            val++;
        }
        dir = (dir + 1) % 4;
        debug("Changed to %d", dir);
        if (dir == 1 || dir == 3) {
            num_steps--;
            debug("Changed num_steps to %d", num_steps);
        }
    }
    return answer;
}

int main(int argc, char **argv) {
    int n = std::stoi(argv[1]);
    int** answer = spiral(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << answer[i][j] << '\t';
        }
        std::cout << std::endl;
    }
    return 0;
}
