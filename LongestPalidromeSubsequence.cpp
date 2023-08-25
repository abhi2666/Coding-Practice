class Solution {
public:

    int LCS(int i, int j, string& s, string &rs, vector<vector<int>>&dp){
        if(i < 0 || j < 0) return 0;
        if(dp[i][j]) return dp[i][j];
        // if characters matches
        if(s[i] == rs[j])
        {
            return dp[i][j] =  1 + LCS(i-1, j-1, s, rs, dp);
        }
        // if not matches
        return dp[i][j] = max(LCS(i-1, j, s, rs, dp), LCS(i, j-1, s, rs, dp));
    }

    int longestPalindromeSubseq(string s) {
        string rs = s;
        reverse(rs.begin(), rs.end());
        int size = s.size()-1;
        vector<vector<int>>dp(size+1, vector<int>(size+1, 0));
        return LCS(size, size, s, rs, dp);
    }
};

// tabulation
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        
        string rs = s;
        reverse(rs.begin(), rs.end());
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[i - 1] == rs[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return dp[n][n];
    }
};
