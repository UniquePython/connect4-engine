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

void print_board(const Board *b)
{
    if (!b)
        return;

    for (int row = ROWS - 1; row >= 0; row--)
    {
        for (int col = 0; col < COLS; col++)
            printf("%s ", b->board[row][col] == PIECE_NONE ? "." : b->board[row][col] == PIECE_PLAYER1 ? "X"
                                                                                                       : "O");
        printf("\n");
    }
}

int main(void)
{
    Board b;
    init_board(&b);

    while (1)
    {
        print_board(&b);

        printf("\nCurrent Player: %s\n", b.curr_player == PIECE_PLAYER1 ? "X" : "O");

        int col;

        while (1)
        {
            printf("Enter column (0-%d): ", COLS - 1);

            if (scanf("%d", &col) != 1)
            {
                // invalid input (e.g., letters)
                printf("Invalid input! Please enter a number.\n");

                // clear input buffer
                int ch;
                while ((ch = getchar()) != '\n' && ch != EOF)
                    ;
                continue;
            }

            if (col < 0 || col >= COLS)
            {
                printf("Column out of range! Try again.\n");
                continue;
            }

            if (!drop_piece(&b, col))
            {
                printf("Column is full! Try another.\n");
                continue;
            }

            break; // valid move
        }
    }

    return 0;
}
