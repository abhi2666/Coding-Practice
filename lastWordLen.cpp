class Solution {
public:
    int lengthOfLastWord(string s) {
        int j = s.size() - 1;
        
        // Skip trailing spaces
        while (j >= 0 && s[j] == ' ')
            j--;
        
        int cnt = 0;
        
        // Count the length of the last word
        while (j >= 0 && s[j] != ' ') {
            j--;
            cnt++;
        }
        
        return cnt;
    }
};
