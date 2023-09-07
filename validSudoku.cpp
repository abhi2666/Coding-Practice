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
        // we will put our data into a set in the form of a string
        // like row-rowNo-value, col-colno-value, grid-gridno-value
        // and through this we can do the code in single pass 
        // to calculate which grid does the element belongs.. we can use formula-
        // (row/3)*3+col/3
        // if we don't find the elements in set then we will put them in and if we do find the
        // elements then it means there is a duplicate element - return false
        unorderd_set<string>st;
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] != '.')
                {
                    string row = "row" + to_string(i)+to_string(board[i][j]);
                    string col = "col" + to_string(j)+to_string(board[i][j]);
                    string grid = "grid" + to_string((i/3)*3(j/3))+to_string(board[i][j]);
                    // check if any of these are already present or nots
                    if(st.find(row) != st.end() || st.find(col) != st.end() || st.find(grid) != st.end()) return false;
                    // add the elements into set
                    st.insert(row);
                    st.insert(col);
                    st.insert(grid);

                }
            }
        }
        return true;
    }
};