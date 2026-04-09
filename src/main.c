#include <stdio.h>
#include <string.h>
#include <assert.h>

#define ROWS 6
#define COLS 7

typedef enum
{
    PIECE_NONE = 0,
    PIECE_PLAYER1,
    PIECE_PLAYER2,
} Piece;

typedef struct
{
    Piece board[ROWS][COLS];
    Piece curr_player;
    int col_heights[COLS];
} Board;

void init_board(Board *b)
{
    if (!b)
        return;

    memset(b->board, PIECE_NONE, sizeof(b->board));
    b->curr_player = PIECE_PLAYER1;
    memset(b->col_heights, 0, sizeof(b->col_heights));
}

int where_to_drop_piece(const Board *b, int col)
{
    assert(0 <= col && col <= ROWS);
    int height = b->col_heights[col];
    return height == ROWS ? -1 : height;
}

int main(void)
{
    Board b;

    init_board(&b);

    printf("connect4-engine\n");
    return 0;
}
