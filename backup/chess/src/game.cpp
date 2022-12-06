#include "game.h"

void Game::create_pieces() 
{/*{{{*/
    for (int i = 0; i < BOARD_WIDTH; i++) {
        whites[i] = new Pawn(white);
        blacks[i] = new Pawn(black);
    }
    whites[knight1] = new Knight(white);
    whites[knight2] = new Knight(white);
    whites[bishop1] = new Bishop(white);
    whites[bishop2] = new Bishop(white);
    whites[rook1] = new Rook(white);
    whites[rook2] = new Rook(white);
    whites[queen] = new Queen(white);
    whites[king] = new King(white);

    blacks[knight1] = new Knight(black);
    blacks[knight2] = new Knight(black);
    blacks[bishop1] = new Bishop(black);
    blacks[bishop2] = new Bishop(black);
    blacks[rook1] = new Rook(black);
    blacks[rook2] = new Rook(black);
    blacks[queen] = new Queen(black);
    blacks[king] = new King(black);
}/*}}}*/

void Game::setup_board() 
{/*{{{*/
    Position* first_pos = new Position();
    
    for (int i = 0; i < BOARD_WIDTH; i++) {
        first_pos->place_piece(whites[i],i,1);
        first_pos->place_piece(blacks[i],i,6);
    }
    
    first_pos->place_piece(whites[knight1],1,0);
    first_pos->place_piece(whites[knight2],6,0);
    first_pos->place_piece(whites[bishop1],2,0);
    first_pos->place_piece(whites[bishop2],5,0);
    first_pos->place_piece(whites[rook1],0,0);
    first_pos->place_piece(whites[rook2],7,0);
    first_pos->place_piece(whites[queen],3,0);
    first_pos->place_piece(whites[king],4,0);

    first_pos->place_piece(blacks[knight1],1,7);
    first_pos->place_piece(blacks[knight2],6,7);
    first_pos->place_piece(blacks[bishop1],2,7);
    first_pos->place_piece(blacks[bishop2],5,7);
    first_pos->place_piece(blacks[rook1],0,7);
    first_pos->place_piece(blacks[rook2],7,7);
    first_pos->place_piece(blacks[queen],3,7);
    first_pos->place_piece(blacks[king],4,7);

    positions.push_back(first_pos);
}/*}}}*/

void Game::del_all_pos() 
{/*{{{*/
    for (auto it = positions.begin(); it != positions.end(); it++) {
        delete *it;
    }
}/*}}}*/


void Game::del_all_pieces(void)
{/*{{{*/
    for (int i = 0; i < NUM_PIECE; i++) {
        delete whites[i];
        delete blacks[i];
    }
}/*}}}*/


bool Game::move(int s_x, int s_y, int t_x, int t_y) 
{/*{{{*/
    if (!valid_coord(s_x,s_y) || !valid_coord(t_x,t_y)) {
        debug("Game::move: Invalid coord: %d %d %d %d",
            s_x, s_y, t_x, t_y);
        return false;
    }

    Position* curr_pos = positions[mv_id];
    if (curr_pos->chk_empty(s_x, s_y)) {
        debug("Game::move: source coord empty: %d %d",
            s_x, s_y);
        return false;
    }

    if (!curr_pos->chk_valid_move(s_x,s_y,t_x,t_y)) {
        debug("Game::move: not a valid move. (%d,%d,%d,%d)",
            s_x, s_y, t_x, t_y);
        return false;
    }

    Piece* t_piece = curr_pos->get_piece(t_x, t_y);
    if ( t_piece != nullptr ) {
        t_piece->set_captured(true);
    }

    // copy the prev position
    Position* newobj = new Position;
    curr_pos->copy_board(newobj);     
    // change the piece
    Piece* picked = newobj->rm_piece(s_x,s_y);
    newobj->place_piece(picked,t_x,t_y);  

    // store in vector and update mv_id    
    positions.push_back(newobj);
    mv_id += 1;
    return true;
}/*}}}*/
