#include <assert.h>
#include <stdlib.h>
#include <algorithm>
#include "dbg.h"
#include "position.h"

static bool chk_same_coord(int s_x, int s_y, int t_x, int t_y) {
    return (s_x == t_x && s_y == t_y)? true : false;
}


Position::Position(void)
{
    for (int i = 0; i < BOARD_HEIGHT; i++)
    {
        for (int j = 0; j < BOARD_WIDTH; j++)
        {
            board.set(nullptr,j,i);
        }
    }
}


void Position::setup(void)
{
    board.set(new Rook(white),      0, 0);
    board.set(new Knight(white),    1, 0);
    board.set(new Bishop(white),    2, 0);
    board.set(new Queen(white),     3, 0);
    board.set(new King(white),      4, 0);
    board.set(new Bishop(white),    5, 0);
    board.set(new Knight(white),    6, 0);
    board.set(new Rook(white),      7, 0);
    for (int j = 0; j < BOARD_WIDTH; j++)
    {
        board.set(new Pawn(white),  j, 1);
    }
    for (int j = 0; j < BOARD_WIDTH; j++)
    {
        board.set(new Pawn(black),  j, BOARD_HEIGHT-2);
    }
    board.set(new Rook(black),      0, BOARD_HEIGHT-1);
    board.set(new Knight(black),    1, BOARD_HEIGHT-1);
    board.set(new Bishop(black),    2, BOARD_HEIGHT-1);
    board.set(new Queen(black),     3, BOARD_HEIGHT-1);
    board.set(new King(black),      4, BOARD_HEIGHT-1);
    board.set(new Bishop(black),    5, BOARD_HEIGHT-1);
    board.set(new Knight(black),    6, BOARD_HEIGHT-1);
    board.set(new Rook(black),      7, BOARD_HEIGHT-1);
}

void Position::prn_board()
{
    for (int i = BOARD_HEIGHT-1; i >= 0; i--)
    {
        for (int j = 0; j < BOARD_WIDTH; j++)
        {
            Piece* piece = board.get(j,i);
            if (piece != nullptr)
            {
                std::cout << piece->prn_piece();    
            } 
            else {
                std::cout << "..";
            }
            std::cout << '\t';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Position::prn_pointers()
{
    for (int i = 0; i < BOARD_HEIGHT; i++)
    {
        for (int j = 0; j < BOARD_WIDTH; j++)
        {
            std::cout << board.get(j,i) << '\t';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Position::prn_allposmov(int s_x, int s_y)
{
    for (int i = BOARD_HEIGHT-1; i >= 0; i--)
    {
        for (int j = 0; j < BOARD_WIDTH; j++)
        {
            if (moves.get_evaled(s_x,s_y,j,i)) {
                if (moves.get_posmov(s_x,s_y,j,i)) {
                    std::cout << "yy";
                }
                else {
                    std::cout << "nn";
                }
            }
            else {
                std::cout << "..";
            }
            std::cout << '\t';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

bool Position::valid_pos(int x, int y)
{
    if (x < 0 || y < 0 || x >= BOARD_WIDTH || y >= BOARD_HEIGHT)
    {
        return false;
    } 
    else {
        return true;
    }
}

bool Position::chk_empty(int x, int y)
{
    // assumes that x and y are valid
    if (board.get(x,y) == nullptr)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

Piece* Position::get_piece(int x, int y)
{
    // assumes that the position is valid.
    return board.get(x,y);
}

Color Position::get_color(int x, int y)
{
    // assumes that the position is valid and contains a piece 
    return board.get(x,y)->get_color();
}

Piece* Position::rm_piece(int x, int y)
{
    Piece* retval = board.get(x,y);
    board.set(nullptr,x,y);
    return retval;
}

void Position::place_piece(Piece* piece, int x, int y)
{
    board.set(piece,x,y);
}

void Position::copy_board(Position* pos)
{
    // Does not copy moves
    for (int i = 0; i < BOARD_HEIGHT; i++) 
    {
        for (int j = 0; j < BOARD_WIDTH; j++) 
        {
            pos->place_piece(board.get(j,i), j, i);
        }
    }
}

bool Position::eval_move(int s_x, int s_y, int t_x, int t_y)
{
    // Evaluates the move and update in moves
    // returns false if fails to update
    // assumes coordinates are valid
    return moves.eval_move(this,s_x, s_y, t_x, t_y);
}


bool Position::chk_valid_move(int s_x, int s_y, int t_x, int t_y) {
    if (moves.get_evaled(s_x,s_y,t_x,t_y)) {
        return moves.get_posmov(s_x,s_y,t_x,t_y);
    }
        
    if (eval_move(s_x,s_y,t_x,t_y)) {
        if (moves.get_evaled(s_x,s_y,t_x,t_y)) {
            return moves.get_posmov(s_x,s_y,t_x,t_y);
        }
        else {
            log_err("Position::chk_valid_move: eval_move returned true but dest evaled not set.");
            log_err("(%d,%d,%d,%d)",s_x,s_y,t_x,t_y);
            return false;
        }
    }
    else {
        log_err("Position::chk_valid_move: eval_move did not return true when it should.");
        log_err("(%d,%d,%d,%d)",s_x,s_y,t_x,t_y);
        return false;
    }
}



bool Position::PosMov::eval_move(Position* pos,int s_x,int s_y,int t_x,int t_y)
{
    // Evaluates the move and update in posmov
    // returns false if it fails to update
    // assumes coordinates are valid
    if (get_evaled(s_x,s_y,t_x,t_y))
    {
        debug("PosMov::eval_point: already evaled at (%d,%d,%d,%d)", s_x, s_y, t_x,t_y);
        return false;
    }
   
    // Sanity check
    Piece* src_piece = pos->board.get(s_x,s_y);
    if (src_piece == nullptr) 
    {
        debug("PosMov::eval_point: src is null (%d,%d,%d,%d)", s_x, s_y, t_x,t_y);
        set(false, s_x, s_y, t_x, t_y);
        return true;
    }
    else if (chk_same_coord(s_x,s_y,t_x,t_y)) {
        debug("PosMov::eval_point: same coord target (%d,%d,%d,%d)", s_x, s_y, t_x,t_y);
        set(false, s_x, s_y, t_x, t_y);
        return true;
    }
    else if (!pos->chk_empty(t_x,t_y) && pos->chk_same_color(s_x,s_y,t_x,t_y)) {
        set(false, s_x, s_y, t_x, t_y);
        return true;
    }

    // Check if the move is supported by the piece
    if (!src_piece->eligible_move(s_x,s_y,t_x,t_y)) {
        set(false,s_x,s_y,t_x,t_y);
        return true;
    }


    // Handle cases depending on board position
    PieceType type = src_piece->get_type();
    int diff_x = t_x - s_x;
    int diff_y = t_y - s_y;
    int dir_x, dir_y;
    int curr_x, curr_y;
    bool propagate;
    
    switch(type) {
        case pawn :
            if ( abs(diff_y) == 2 ) {
                // pawn moving 2 at first
                // moved check is already done in eligible_move
                if (pos->chk_empty(t_x,t_y-(diff_y/2)) && pos->chk_empty(t_x,t_y)) {
                    debug("PosMov::eval_point: pawn moving 2 (%d,%d,%d,%d)", s_x, s_y, t_x,t_y);
                    set(true,s_x,s_y,t_x,t_y);
                }
                else {
                    debug("PosMov::eval_point: pawn moving 2 but blocked (%d,%d,%d,%d)", s_x, s_y, t_x,t_y);
                    set(false,s_x,s_y,t_x,t_y);
                }
            }
            else if ( abs(diff_x) == 1 ) {
                // pawn capturing diagonal
                if (pos->chk_empty(t_x,t_y)) {
                    debug("PosMov::eval_point: pawn capture but not there (%d,%d,%d,%d)", s_x, s_y, t_x,t_y);
                    set(false,s_x,s_y,t_x,t_y);        
                }
                else {
                    // same color check is already done, so diff color
                    debug("PosMov::eval_point: pawn capture (%d,%d,%d,%d)", s_x, s_y, t_x,t_y);
                    set(true,s_x,s_y,t_x,t_y);
                }
            }
            else {
                // typical one square move
                if (pos->chk_empty(t_x,t_y)) {
                    debug("PosMov::eval_point: pawn moving 1 (%d,%d,%d,%d)", s_x, s_y, t_x,t_y);
                    set(true,s_x,s_y,t_x,t_y);
                }
                else {
                    debug("PosMov::eval_point: pawn moving 1 but blocked. (%d,%d,%d,%d)", s_x, s_y, t_x,t_y);
                    set(false,s_x,s_y,t_x,t_y);        
                }
            }
            break;
        case knight:
        case king :
            // the coordinates are assumed to be valid and same color check is done.
            // hence, always possible move
            debug("PosMov::eval_point: knight or king moving. (%d,%d,%d,%d)", s_x, s_y, t_x,t_y);
            set(true,s_x,s_y,t_x,t_y);
            break;
        default : // bishop, rook, queen
            dir_x = (diff_x == 0)? 0 : diff_x / abs(diff_x);
            dir_y = (diff_y == 0)? 0 : diff_y / abs(diff_y);
            // identify possible moves by going from source to dest
            propagate = true;
            for ( int i = 1; i <= std::max(abs(diff_x),abs(diff_y)) ; i++) {
                curr_x = s_x + (dir_x * i);
                curr_y = s_y + (dir_y * i);
                if (pos->chk_empty(curr_x,curr_y)) {
                    set(propagate,s_x,s_y,curr_x,curr_y);
                }
                else {
                    if (pos->chk_same_color(s_x,s_y,curr_x,curr_y)) {
                        set(false,s_x,s_y,curr_x,curr_y);
                    }
                    else {
                        set(propagate,s_x,s_y,curr_x,curr_y);
                    }
                    propagate = false;
                }
            }
    }

    return true;
}


void Position::eval_allposmov(int s_x, int s_y) {
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            eval_move(s_x,s_y,j,i);
        }
    }
}

