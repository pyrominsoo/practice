#ifndef _POSITION_H_
#define _POSITION_H_

#include <iostream>
#include <string>
#include <vector>
#include <utility>

#include "chessparam.h"
#include "piece.h"
#include "board.h"
#include "dbg.h"



class Position
{
public:

	Position();

	~Position() { } 


	void setup();

	void prn_board(); 
	void prn_pointers();
    void prn_allposmov(int s_x, int s_y);

	bool valid_pos(int x, int y);
	bool chk_empty(int x, int y);
	Piece* rm_piece(int x, int y);
	void place_piece(Piece* piece, int x, int y);
	Piece* get_piece(int x, int y);
	Color get_color(int x, int y);

	void copy_board(Position* pos);

	bool eval_move(int s_x, int s_y, int t_x, int t_y);
    bool chk_same_color(int s_x,int s_y,int t_x,int t_y) {
        return (get_color(s_x,s_y) == get_color(t_x,t_y))? true : false;
    }
    bool chk_valid_move(int s_x,int s_y,int t_x,int t_y);
    void eval_allposmov(int s_x, int s_y);


private:
	class PosMov
	{
		public:
            PosMov( ) {
                for (int i = 0; i < BOARD_HEIGHT; i++) {
                    for (int j = 0; j < BOARD_WIDTH; j++) {
                        for (int k = 0; k < BOARD_HEIGHT; k++) {
                            for (int l = 0; l < BOARD_WIDTH; l++) {
                                evaled.set(false,j,i,l,k);
                                posmov.set(false,j,i,l,k);
                            }
                        }
                    }
                }
            }

            ~PosMov() { }

			void set(bool val, int s_x, int s_y, int t_x, int t_y) 
            {
                evaled.set(true,s_x,s_y,t_x,t_y);
                posmov.set(val,s_x,s_y,t_x,t_y);
			}

			bool get_evaled(int s_x, int s_y, int t_x, int t_y) 
            {
				return evaled.get(s_x,s_y,t_x,t_y);
			}
			
            bool get_posmov(int s_x, int s_y, int t_x, int t_y) 
            {
				return posmov.get(s_x,s_y,t_x,t_y);
			}

			bool eval_move(Position* pos, int s_x, int s_y, int t_x, int t_y);
		private:
			DblBoardBool evaled;
			DblBoardBool posmov;
	};
	Board<Piece*> board;
	PosMov moves;

};

#endif
