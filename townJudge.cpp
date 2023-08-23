class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>hash(n + 1, 0);
        for(auto it : trust)
        {
            hash[it[0]]--;
            hash[it[1]]++;
        }
        for(auto h : hash)
        {
            if(h == n-2) return h;
        }
        return -1;
    }
};