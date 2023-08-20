/*
Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

Approach --> you will have to go to all the paths and find the minimum out of all.
*/

class Solution {
public:
    int getPaths(int n, int m, vector<vector<int>>&dp, vector<vector<int>>&grid)
    {
        if(n  == 0 && m == 0) return grid[n][m];
        if(n < 0 || m < 0) return 1000; // goes out of bound in that case we want to reject that paths
        if(dp[n][m] != 0) return dp[n][m];
        int up = grid[n][m] + getPaths(n-1, m, grid);
        int right = grid[n][m] + getPaths(n, m - 1, grid);

        return dp[n][m] = min(up, right);
    }

    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>>dp;
        int n = grid.size();
        int m = grid[0].size();
        return getPaths(n-1, m - 1, dp, grid);
    }
};