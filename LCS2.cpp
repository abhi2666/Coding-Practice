class Solution {
public:
    int getSequence(int i, int j,  vector<vector<int>>&dp, string& text1, string& text2)
    {
        if(i < 0 || j < 0) return 0;
        if(dp[i][j]) return dp[i][j];
        if(text1[i] == text2[j])
        {
            return dp[i][j] = 1 + getSequence(i-1, j-1, dp, text1, text2);
        }
        
        // if they do not matches 
        return dp[i][j] = max(getSequence(i-1, j, dp, text1, text2), getSequence(i, j-1, dp, text1, text2));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int i = text1.size(), j = text2.size();
        vector<vector<int>>dp(i, vector<int>(j, 0));
        return getSequence(i-1, j-1, dp, text1, text2);
    }
};