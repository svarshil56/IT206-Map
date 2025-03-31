#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool isValidSudoku(vector<vector<char>> &board)
{
    map<int, map<char, int>> rows, cols, boxes;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            char num = board[i][j];
            if (num == '.')
                continue;

            int boxIndex = (i / 3) * 3 + (j / 3);

            if (rows[i][num]++ > 0 || cols[j][num]++ > 0 || boxes[boxIndex][num]++ > 0)
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    if (isValidSudoku(board))
    {
        cout << "Valid Sudoku" << endl;
    }
    else
    {
        cout << "Invalid Sudoku" << endl;
    }

    return 0;
}
