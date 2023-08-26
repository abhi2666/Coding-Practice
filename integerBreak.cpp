/*
Input: n = 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
*/
class Solution {
public:
    int breakNum(int num, vector<int>&dp)
    {
        if(num == 1) return 1;
        if(dp[num]) return dp[num]; 
        int ans = num;
        for(int i = 1; i <= num/2; i++)
        {
            ans = max(ans, i*(breakNum(num-i, dp))); // 
        }

        return dp[num] = ans;
    }

    int integerBreak(int n) {
        vector<int>dp(n+1, 0);
        if(n < 4) return n-1;
        return breakNum(n, dp);
    }
};