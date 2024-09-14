#include <stdio.h>

#define SIZE 3

// Function to check the win condition
char checkWin(char board[SIZE][SIZE])
{
    int i;

    // Check rows
    for (i = 0; i < SIZE; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '-')
        {
            return board[i][0];
        }
    }

    // Check columns
    for (i = 0; i < SIZE; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '-')
        {
            return board[0][i];
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '-')
    {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '-')
    {
        return board[0][2];
    }

    // No winner yet
    return '-';
}

// Function to handle a player's move
void move(char board[SIZE][SIZE], char player)
{
    int row, col;

    while (1)
    {
        printf("Enter Row for %c (0-2) = ", player);
        scanf("%d", &row);
        printf("Enter Column for %c (0-2) = ", player);
        scanf("%d", &col);

        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE)
        {
            if (board[row][col] == '-')
            {
                board[row][col] = player;
                break;
            }
            else
            {
                printf("Cell is already occupied. Try again.\n");
            }
        }
        else
        {
            printf("Invalid input. Try again.\n");
        }
    }

    // Print the board after the move
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf(" %c ", board[i][j]);
            if (j < 2)
            {
                printf("|");
            }
        }
        printf("\n");
        if (i < 2)
        {
            printf("---|---|---\n");
        }
    }
}

int main()
{
    char board[SIZE][SIZE] =
    {
        {'-', '-', '-'},
        {'-', '-', '-'},
        {'-', '-', '-'}
    };

    char winner = '-';
    int moves = 0;

    printf("Current Board:\n");
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n");
    }

    while (moves < SIZE * SIZE && winner == '-')
    {
        if (moves % 2 == 0)
        {
            move(board, 'X');
        }
        else
        {
            move(board, 'O');
        }
        winner = checkWin(board);
        moves++;
    }

    if (winner != '-')
    {
        printf("The winner is: %c\n", winner);
    }
    else
    {
        printf("It's a draw!\n");
    }

    return 0;
}
