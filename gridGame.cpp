/*
Input: grid = [[2,5,4],[1,5,1]]
Output: 4
Explanation: The optimal path taken by the first robot is shown in red, and the optimal path taken by the second robot is shown in blue.
The cells visited by the first robot are set to 0.
The second robot will collect 0 + 0 + 4 + 0 = 4 points.
*/

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long top = 0, bottom = 0, ans = LLONG_MAX;
        int n = grid[0].size();
        for(int i = 0; i < n; i++)
        {
            top += grid[0][i];
        }

        for(int i = 0; i < n; i++)
        {
            top -= grid[0][i];
            ans = min(ans, max(top, bottom)); // because first robot wants to minimize the profit
            // and second robot wants to maximize the profit it earns
            bottom = += grid[1][i];
        }
        return ans;
    }
};