#include "tetris.h"

char piece_type_to_char(PieceType piece_type)
{
    static char PIECE_CHARS[7] =
        {'O', 'I', 'T', 'L', 'J', 'S', 'Z'};
    return PIECE_CHARS[piece_type];
}

bool piece_shift(Piece *piece, int dx, int dy, Board *board)
{
    piece->x += dx;
    piece->y += dy;
    int *bounds = PIECE_LOCATION_BOUNDS[piece->type][piece->rot];
    if (piece->x < bounds[0] || piece->x > bounds[1] || piece->y < bounds[2] || piece->y > bounds[4] || piece_intersects_board(piece, board))
    {
        piece->x -= dx;
        piece->y -= dy;
        return false;
    }
    return true;
}

bool piece_rot(Piece *piece, int drot, Board *board)
{
    // TODO
}

bool piece_intersects_board(Piece *piece, Board *board)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int x = piece->x + i;
            int y = piece->y + j;
            if (x < 0 || x >= BOARD_WIDTH || y < 0 || y >= BOARD_HEIGHT)
            {
                continue;
            }
            bool tile = PIECE_SHAPE[piece->type][piece->rot][i][j];
            if (tile && board->matrix[x][y])
            {
                return true;
            }
        }
    }
    return false;
}