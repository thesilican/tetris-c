#ifndef TETRIS_H
#define TETRIS_H
#include <stdint.h>
#include <stdbool.h>

#define BOARD_WIDTH 10
#define BOARD_HEIGHT 40
#define GAME_QUEUE_LEN 16

typedef struct Rng Rng;
typedef enum PieceType PieceType;
typedef struct Piece Piece;
typedef enum Tile Tile;
typedef struct Board Board;
typedef struct Bag Bag;
typedef enum GameAction GameAction;
typedef struct Game Game;

struct Rng
{
    uint32_t state;
};

Rng rng_new(uint32_t seed);

uint32_t rng_next(Rng *rng);

enum PieceType
{
    PIECE_O,
    PIECE_I,
    PIECE_T,
    PIECE_L,
    PIECE_J,
    PIECE_S,
    PIECE_Z,
};

char piece_type_to_char(PieceType piece_type);

struct Piece
{
    PieceType type;
    int x;
    int y;
    int rot;
};

bool piece_shift(Piece *piece, int dx, int dy, Board *board);

bool piece_rot(Piece *piece, int drot, Board *board);

bool piece_intersects_board(Piece *piece, Board *board);

bool PIECE_SHAPE[7][4][4][4];

int PIECE_SPAWN_LOCATION[7][2];

struct PieceKickSeq
{
    int len;
    int shifts[5][2];
} PIECE_KICK_TABLE[7][4][4];

int PIECE_LOCATION_BOUNDS[7][4][4];

enum Tile
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
};

char tile_to_char(Tile tile);

struct Board
{
    Tile matrix[BOARD_WIDTH][BOARD_HEIGHT];
};

Board board_new();

void board_lock(Board *board, Piece *piece);

struct Bag
{
    Rng rng;
    PieceType pieces[7];
};

Bag bag_new(int seed);

void bag_shuffle(Bag *bag);

enum GameAction
{
    GA_SHIFT_LEFT,
    GA_SHIFT_RIGHT,
    GA_SHIFT_DOWN,
    GA_SOFT_DROP,
    GA_ROT_CW,
    GA_ROT_180,
    GA_ROT_CCW,
    GA_LOCK,
    GA_HOLD,
    GA_HARD_DROP
};

struct Game
{
    Piece active;
    PieceType hold;
    bool has_hold;
    bool can_hold;
    PieceType queue[GAME_QUEUE_LEN];
    int queue_len;
    Bag bag;
    Board board;
};

Game game_new(int seed);

void game_apply_action(Game *game, GameAction action);

void game_print(Game *game);

#endif