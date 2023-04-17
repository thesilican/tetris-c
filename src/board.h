#ifndef BOARD_H
#define BOARD_H
#include "piece.h"

#define BOARD_WIDTH 10
#define BOARD_HEIGHT 40

typedef enum Tile
{
    TILE_NONE,
    TILE_O,
    TILE_I,
    TILE_T,
    TILE_L,
    TILE_J,
    TILE_S,
    TILE_Z,
    TILE_GRAY
} Tile;

typedef struct Board
{
    Tile matrix[BOARD_WIDTH][BOARD_HEIGHT];
} Board;

Board board_new();

#endif