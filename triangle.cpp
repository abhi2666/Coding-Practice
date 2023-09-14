// Given a triangle array, return the minimum path sum from top to bottom.
/*
For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.
Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
*/

class Solution {
public:
    int getMinPath(int n, int m, int size, vector<vector<int>>&triangle, vector<vector<int>>&dp)
    {   
        if(n == size) return 0;
        if(dp[n][m] != -1) return dp[n][m];
        // we can either go for n+1,m or n+1, m +1

        int a = triangle[n][m] + getMinPath(n+1, m, size, triangle, dp);
        int b = triangle[n][m] + getMinPath(n+1, m+1, size, triangle, dp);

        return dp[n][m] = min(a, b);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int size = triangle.size();
        vector<vector<int>>dp(size, vector<int>(size, -1));
        return getMinPath(0, 0, size, triangle, dp);
    }
};