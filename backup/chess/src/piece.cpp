#include <string>
#include <stdlib.h>
#include "dbg.h"
#include "piece.h"

std::string Pawn::prn_piece() {
    std::string answer = "";
    if (color == black) {
        answer += "b";
    } else {
        answer += "w";
    }
    answer += "p";
    return answer;
}

std::string Knight::prn_piece() {
    std::string answer = "";
    if (color == black) {
        answer += "b";
    } else {
        answer += "w";
    }
    answer += "n";
    return answer;
}

std::string Bishop::prn_piece() {
    std::string answer = "";
    if (color == black) {
        answer += "b";
    } else {
        answer += "w";
    }
    answer += "b";
    return answer;
}

std::string Rook::prn_piece() {
    std::string answer = "";
    if (color == black) {
        answer += "b";
    } else {
        answer += "w";
    }
    answer += "r";
    return answer;
}

std::string Queen::prn_piece() {
    std::string answer = "";
    if (color == black) {
        answer += "b";
    } else {
        answer += "w";
    }
    answer += "q";
    return answer;
}

std::string King::prn_piece() {
    std::string answer = "";
    if (color == black) {
        answer += "b";
    } else {
        answer += "w";
    }
    answer += "k";
    return answer;
}


bool Pawn::eligible_move(int s_x, int s_y, int t_x, int t_y) {
    // assumes that the coordinates are valid (within board)
    
    int dir;
    if (color == white) {
        dir = 1;
    }
    else {
        dir = -1;
    }
    
    int diff_x = t_x - s_x;
    int diff_y = t_y - s_y;
    if (diff_x == 0) {
        if (diff_y == (dir*1)) {
            //possible 1 step move
            return true;
        }
        else if (diff_y == (dir*2)) {
            //possible 2 step move
            return (moved)? false : true;
        }
        else {
            return false;
        }
    }
    else if (abs(diff_x) == 1) {
        return (diff_y == (dir*1))? true : false;
    }
    else {
        return false;
    }
}

bool Knight::eligible_move(int s_x, int s_y, int t_x, int t_y) {
    // assumes that the coordinates are valid (within board)
    int diff_x = t_x - s_x;
    int diff_y = t_y - s_y;
    if (((abs(diff_x)+abs(diff_y)) == 3) && (diff_x != 0 ) && (diff_y != 0)) {
        return true;
    }
    else {
        return false;
    }
}

bool Bishop::eligible_move(int s_x, int s_y, int t_x, int t_y) {
    // assumes that the coordinates are valid (within board)
    int diff_x = t_x - s_x;
    int diff_y = t_y - s_y;
    if ((abs(diff_x) == abs(diff_y)) && (diff_x != 0)) {
        return true;
    }
    else {
        return false;
    }
}

bool Rook::eligible_move(int s_x, int s_y, int t_x, int t_y) {
    // assumes that the coordinates are valid (within board)
    int diff_x = t_x - s_x;
    int diff_y = t_y - s_y;

    if (diff_x == 0 || diff_y == 0) {
        return true;
    }
    else {
        return false;
    }
}

bool Queen::eligible_move(int s_x, int s_y, int t_x, int t_y) {
    // assumes that the coordinates are valid (within board)
    int diff_x = t_x - s_x;
    int diff_y = t_y - s_y;
    
    if ((abs(diff_x) == abs(diff_y)) && (diff_x != 0)) 
        return true;
    if (diff_x == 0 || diff_y == 0) 
        return true;
    return false;

}

bool King::eligible_move(int s_x, int s_y, int t_x, int t_y) {
    // assumes that the coordinates are valid (within board)
    int diff_x = t_x - s_x;
    int diff_y = t_y - s_y;
    
    if ((abs(diff_x) == abs(diff_y)) && (abs(diff_x) == 1)) {
        return true;
    }
    if (diff_x == 0 && abs(diff_y) == 1) {
        return true;
    }
    if (diff_y == 0 && abs(diff_x) == 1) {
        return true;
    }
    return false;
}
