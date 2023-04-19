#ifndef _GAME_H
#define _GAME_H

#include <string>
#include <vector>
#include "chessparam.h"
#include "piece.h"
#include "position.h"
#include "dbg.h"

/*
 * class Game manages a game of chess.
 * It is primarily made of a series of positions kept in a vector
 */
class Game
{
    enum PieceID {
        pawn1 = 0,
        pawn2 = 1,
        pawn3 = 2,
        pawn4 = 3,
        pawn5 = 4,
        pawn6 = 5,
        pawn7 = 6,
        pawn8 = 7,
        knight1 = 8,
        knight2 = 9,
        bishop1 = 10,
        bishop2 = 11,
        rook1 = 12,
        rook2 = 13,
        queen = 14,
        king = 15
    };

    public:
        Game(int id, std::string name) : id{id}, name{name} {
            positions.reserve(NUM_POS);
            create_pieces();
            setup_board();
            mv_id = 0;
        }

        ~Game() {
            del_all_pos();
            del_all_pieces();
        }

        void prn_curr_pos() {
            debug("positions.size(): %d",(int)positions.size());
            debug("mv_id: %d",mv_id);
            debug("positions[mv_id]: %p",positions[mv_id]);
            positions[mv_id]->prn_board();
        }

        bool move(int s_x, int s_y, int t_x, int t_y);
        bool valid_coord(int x, int y) {
            if (x >= BOARD_WIDTH || x < 0) return false;
            if (y >= BOARD_HEIGHT || y < 0) return false;
            return true;
        }

        void prn_allposmov(int s_x, int s_y) {
            positions.at(mv_id)->eval_allposmov(s_x,s_y);
            positions.at(mv_id)->prn_allposmov(s_x,s_y);
        }
    private:
        int id;
        std::string name;
        // holds list of pieces.
        // Refer to PieceID for the location of each piece
        Piece* whites[NUM_PIECE];
        Piece* blacks[NUM_PIECE];
        std::vector<Position*> positions;
        int mv_id;

        void create_pieces();
        void setup_board();
        void del_all_pos();
        void del_all_pieces();
};

#endif
