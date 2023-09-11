#include <iostream>
#include <cmath>
using namespace std;

const int N = 4;

void printBoard(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(int row, int col, int board[N][N], int n)
{
    for (int i = 0; i < N; i++)
    {
        if (board[i][col] == n || board[row][i] == n)
        {
            return false;
        }
    }
    int s = sqrt(N);
    int rs = row - (row % s);
    int cs = col - (col % s);
    for (int r = 0; r < s; r++)
    {
        for (int c = 0; c < s; c++)
        {
            if (board[rs + r][cs + c] == n)
            {
                return false;
            }
        }
    }
    return true;
}

bool sudoku(int board[N][N])
{
    int row, col;
    bool isFull = true;

    for (row = 0; row < N; row++)
    {
        for (col = 0; col < N; col++)
        {
            if (board[row][col] == 0)
            {
                isFull = false;
                break;
            }
        }
        if (!isFull)
        {
            break;
        }
    }

    if (isFull)
    {
        printBoard(board);
        return true;
    }

    for (int num = 1; num <= N; num++)
    {
        if (isSafe(row, col, board, num))
        {
            board[row][col] = num;
            if (sudoku(board))
            {
                return true;
            }
            board[row][col] = 0;
        }
    }

    return false;
}

int main()
{
    int board[N][N];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }

    sudoku(board) ? cout << "YES" << endl : cout << "NO" << endl;

    return 0;
}
