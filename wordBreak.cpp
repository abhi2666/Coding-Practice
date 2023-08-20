#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

    int isPossible(int idx, string& s, vector<int>&dp, unordered_set<string>& st)
    {

        if(idx == s.size()) return 1; // since implies that string has reached 
        // and it can reach end only if matching words have been found.

        // pick elements character by character 
        if(dp[i] != -1) return dp[i];
        string temp;
        
        for(int i = idx; i <= s.size(); i++)
        {
            // if string is found in wordDick then inc i + 1 and again make a 
            // recursive call
            temp += s[i];
            if(st.find(temp) != st.end())
            {
                // means current string exists in the wordDict
                // now start from  + 1 index and search for other word
                if(isPossible(i + 1, s, dp, st)) return dp[idx] = 1;
            }
            
        }
        return dp[idx] = 0;
    }

    bool wordBreak(string s, vector<string> &wordDict)
    {
        // make a set of worddict so that finding can become easy
        vector<int>dp(s.size(), -1);
        unordered_set<string>st;
        for(auto it : wordDict)
        {
            st.insert(it);
        }

        return isPossible(0, s, dp, st); 
    }
};