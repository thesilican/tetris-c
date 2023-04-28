#include "tetris.h"

Bag bag_new(int seed)
{
    Bag bag;
    bag.rng = rng_new(seed);
    bag.pieces[0] = PIECE_O;
    bag.pieces[1] = PIECE_I;
    bag.pieces[2] = PIECE_T;
    bag.pieces[3] = PIECE_L;
    bag.pieces[4] = PIECE_J;
    bag.pieces[5] = PIECE_S;
    bag.pieces[6] = PIECE_Z;
    bag_shuffle(&bag);
    return bag;
}

void bag_shuffle(Bag *bag)
{
    for (int i = 6; i >= 1; i--)
    {
        int j = rng_next(&bag->rng) % (i + 1);
        PieceType tmp = bag->pieces[i];
        bag->pieces[i] = bag->pieces[j];
        bag->pieces[j] = tmp;
    }
}

Game game_new(int seed)
{
}