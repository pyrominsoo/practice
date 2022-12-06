#include <iostream>
#include <string>
#include "game.h"

using namespace std;

/*
int get_nxt_num(string s, string delim, int* last, int* next) {
    *next = s.find(delim,*last);
    int result = stoi(s.substr(*last, *next-*last));
    *last = *next + 1;
    return result;
}
*/

int main(void) {
//    string input;
//    string delim = " ";
//    int* next = new int(0);
//    int* last = new int(0);
    int cmd;
    int s_x, s_y, t_x, t_y;


    Game newgame(0, "mygame");
    
    newgame.prn_curr_pos();
    cout << "Type cmd: ";
    cin >> cmd;
    while (cmd != 0) {
        if (cmd == 1) {
            //moving piece
            cin >> s_x;
            cin >> s_y;
            cin >> t_x;
            cin >> t_y;
            if (newgame.valid_coord(s_x,s_y) && newgame.valid_coord(t_x,t_y)) {
                newgame.move(s_x,s_y,t_x,t_y);
                newgame.prn_curr_pos();
            }
            else {
                cout << "Invalid coordinates given." << endl;
            }
        }
        else if (cmd == 2) {
            cin >> s_x;
            cin >> s_y;
            if (newgame.valid_coord(s_x,s_y)) {
                newgame.prn_allposmov(s_x,s_y);
            }
            else {
                cout << "Invalid coordinates given." << endl;
            }
        }
        cout << "Type cmd: ";
        cin >> cmd;
    }
        
//    newgame.prn_curr_pos();
//    newgame.move(4,1,4,3);
//    newgame.prn_curr_pos();
//    newgame.eval_allposmov(1,0);
//    newgame.prn_allposmov(1,0);

    return 0;
}
