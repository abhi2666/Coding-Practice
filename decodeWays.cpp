class Solution {
public:
    int numDecodings(string s) {
        vector<int>dp(s.size()+1, 0);
        dp[0] = 1; // for a string of size 0 char(means nothing is there), there is
        // only 1 way
        dp[1] = s[0] == '0' ? 0 : 1; // for the very first char if its anything but 
        // zero, then you have 1 way of solving it otherwise it will be 0.
        for(int i = 2; i <= s.size(); i++)
        {
            int firstDig = stoi(s.substr(i-1, 1));
            int secondDig = stoi(s.substr(i-2, 2));
            // ex for input "12" where i = 2 means i will be pointing 2
            // firstDigit = 2 and secondDigit = 12 and then we will check these two
            if(firstDig >= 1){
                dp[i] = dp[i-1];
            }
            if(secondDig >= 10 && secondDig <= 26)
            {
                dp[i] += dp[i-2];
            }
        } 
        return dp[s.size()];
    }
};