#ifndef GAME_H
#define GAME_H
#include "board.h"
#include "piece.h"
#include <stdbool.h>
#include "util.h"

#define QUEUE_LEN 16

typedef struct Bag
{
    Rng rng;
    PieceType pieces[7];
} Bag;

Bag bag_new(int seed);

void bag_shuffle(Bag *bag);

typedef struct Game
{
    Piece active;
    PieceType hold;
    bool has_hold;
    bool can_hold;
    PieceType queue[QUEUE_LEN];
    int queue_len;
    Bag bag;
    Board board;
} Game;

Game game_new(int seed);

#endif