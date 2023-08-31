class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int i = 0, j = 1, n = s.size();
        
        // because only upto we will find the substring
        for(int i = 1; i <= n/2; i++)
        {
            if(n % i == 0)
            {
                // means we can pick this size of substring
                string temp = s.substr(0, i);
                int j = i;
                while(j < n && s.substr(j, i) == temp) j++;
                if(j == n) return true;
            }
        }
        return false;
    }
};