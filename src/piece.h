#ifndef PIECE_H
#define PIECE_H

typedef enum PieceType
{
    PIECE_O,
    PIECE_I,
    PIECE_T,
    PIECE_L,
    PIECE_J,
    PIECE_S,
    PIECE_Z,
} PieceType;

char piece_type_to_char(PieceType piece_type);

typedef struct Piece
{
    PieceType type;
    int x;
    int y;
    int rot;
} Piece;

#endif