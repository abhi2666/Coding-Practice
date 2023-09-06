/*
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
*/

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        // we will check for row, columns and 3*3 grid
        // rows
        map<char, int> mp;
        for (int i = 0; i < 9; i++)
        {
            mp.clear();
            for (int j = 0; j < 9; i++)
            {
                if (mp.count(board[i][j]) > 0)
                    return false;
                mp[board[i][j]] = 1;
            }
        }

        // now check for columns
        for (int i = 0; i < 9; i++)
        {
            mp.clear();
            for (int j = 0; j < 9; j++)
            {
                if (mp.count(board[j][i]) > 0)
                    return false;
                mp[board[i][j]] = 1;
            }
        }

        // for 3 * 3 grid
        vector<unordered_set<char>> check_subbox(9);
        for (int row = 0; row < 9; row++)
        {
            for (int col = 0; col < 9; col++)
            {
                int loc = (row / 3) * 3 + col / 3;
                if (board[row][col] != '.' && check_subbox[loc].find(board[row][col]) != check_subbox[loc].end())
                {
                    return false;
                }
                check_subbox[loc].insert(board[row][col]);
            }
        }
        return true;
    }
};