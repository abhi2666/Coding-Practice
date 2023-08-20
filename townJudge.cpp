class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int hash[n+1] = {0};
        for(int i = 0; i < trust.size(); i++)
        {
            hash[trust[i][0]] = -1;
            if(hash[trust[i][1]] != -1)
            {
                hash[trust[i][1]]++;
            }
        }

        for(int i = 0; i < n + 1; i++)
        {
            if(hash[i] > 0) return i;
        }

        return -1;
    }
};