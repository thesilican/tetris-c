#include "tetris.h"

char tile_to_char(Tile tile)
{
    static char TILE_CHARS[9] =
        {' ', 'O', 'I', 'T', 'L', 'J', 'S', 'Z', 'X'};
    return TILE_CHARS[tile];
}

Board board_new()
{
    Board board;
    for (int i = 0; i < BOARD_WIDTH; i++)
    {
        for (int j = 0; j < BOARD_HEIGHT; j++)
        {
            board.matrix[i][j] = TILE_NONE;
        }
    }
    return board;
}