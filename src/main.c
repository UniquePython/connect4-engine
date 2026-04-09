#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

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
    assert(0 <= col && col < COLS);

    int height = b->col_heights[col];
    assert(0 <= height && height <= ROWS);

    return height == ROWS ? -1 : height;
}

bool drop_piece(Board *b, int col)
{
    if (!b)
        return false;

    assert(0 <= col && col < COLS);

    int row = where_to_drop_piece(b, col);
    if (row == -1)
        return false;
    assert(0 <= row && row < ROWS);

    assert(b->board[row][col] == PIECE_NONE);
    b->board[row][col] = b->curr_player;
    b->col_heights[col] += 1;
    b->curr_player = b->curr_player == PIECE_PLAYER1 ? PIECE_PLAYER2 : PIECE_PLAYER1;

    return true;
}

int main(void)
{
    Board b;

    init_board(&b);

    printf("connect4-engine\n");
    return 0;
}
