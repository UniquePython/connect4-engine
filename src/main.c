#include <stdio.h>

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

int main(void)
{
    printf("connect4-engine\n");
    return 0;
}
