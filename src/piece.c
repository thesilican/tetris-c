#include "piece.h"

char piece_type_to_char(PieceType piece_type)
{
    static char PIECE_CHARS[7] =
        {'O', 'I', 'T', 'L', 'J', 'S', 'Z'};
    return PIECE_CHARS[piece_type];
}