#include <stdio.h>
#include <string.h>

typedef enum
{
    PIECE_NONE = 0,
    PIECE_PLAYER1,
    PIECE_PLAYER2,
} Piece;

typedef struct
{
    Piece board[6][7];
    Piece curr_player;
    int col_heights[7];
} Board;

void init_board(Board *b)
{
    if (!b)
        return;

    memset(b->board, PIECE_NONE, sizeof(b->board));
    b->curr_player = PIECE_PLAYER1;
    memset(b->col_heights, 0, sizeof(b->col_heights));
}

int main(void)
{
    Board b;

    init_board(&b);

    printf("connect4-engine\n");
    return 0;
}
