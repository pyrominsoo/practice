#ifndef _PIECE_H_
#define _PIECE_H_

#include <string>

//test this
enum Color{
    white = 0,
    black = 1
};

enum PieceType {
    pawn = 1,
    knight = 2,
    bishop = 3,
    rook = 4,
    queen = 5,
    king = 6
};

class Piece
{
    public:

        Piece(Color color, PieceType type) {
            this->color = color;
            this->type = type;
            this->moved = false;
            this->captured = false;
        }

        virtual ~Piece() {};

        Color get_color() {
            return color;
        }
      
        PieceType get_type() {
            return type;
        }

        // Set moved flag to true. Returns the original value
        bool set_moved() {
            bool retval = moved;
            moved = true;
            return retval;
        }

        bool get_moved() {
            return moved;
        }

        void set_captured(bool newval) {
            captured = newval;        
        }

        bool get_captured() { return captured; }

        virtual std::string prn_piece() = 0;
        virtual bool eligible_move(int s_x, int s_y, int t_x, int t_y) = 0;
            

    protected:
        Color color;
        PieceType type;
        bool moved;
        bool captured;
};

class Pawn : public Piece {
    public:
        Pawn(Color color) :  Piece(color, pawn) {
        }

        ~Pawn() {}

        std::string prn_piece(); 
        bool eligible_move(int s_x, int s_y, int t_x, int t_y);
};

class Knight : public Piece {
    public:
        Knight(Color color) :  Piece(color, knight) {
        }
        
        ~Knight() {}

        std::string prn_piece();
        bool eligible_move(int s_x, int s_y, int t_x, int t_y);
};


class Bishop : public Piece {
    public:
        Bishop(Color color) :  Piece(color, bishop) {
        }

        ~Bishop() {}

        std::string prn_piece();
        bool eligible_move(int s_x, int s_y, int t_x, int t_y);
};

class Rook : public Piece {
    public:
        Rook(Color color) :  Piece(color, rook) {
        }

        ~Rook() {}

        std::string prn_piece();
        bool eligible_move(int s_x, int s_y, int t_x, int t_y);
};

class Queen : public Piece {
    public:
        
        Queen(Color color) :  Piece(color, queen) {
        }
            
        ~Queen() {}

        std::string prn_piece();
        bool eligible_move(int s_x, int s_y, int t_x, int t_y);
};

class King : public Piece {
    public:
        King(Color color) :  Piece(color, king) {
        }

        ~King() {}

        std::string prn_piece();
        bool eligible_move(int s_x, int s_y, int t_x, int t_y);
};

#endif
