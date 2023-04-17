#include "board.h"

Board board_new()
{
    Tile matrix[BOARD_WIDTH][BOARD_HEIGHT];
    for (int i = 0; i < BOARD_WIDTH; i++)
    {
        for (int j = 0; j < BOARD_HEIGHT; j++)
        {
            matrix[i][j] = TILE_NONE;
        }
    }
    Board board = {.matrix = matrix};
    return board;
}