class Solution {
public:
    vector<string>mp = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs" , "tuv", "wxyz"};

    void getCombos(int idx, vector<int>nums, int n, vector<string>&res, string temp)
    {
        if(idx == n)
        {
            res.push_back(temp);
            return;
        }

        for(int i = 0; i < mp[nums[idx]].size(); i++)
        {
            getCombos(idx+1, nums, n, res, temp+mp[nums[idx]][i]);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string>res;
        int n = digits.size();
        if(n == 0) return res;
        vector<int>nums;
        for(auto it : digits)
        {
            nums.push_back(char(it - '0'));
        }
        // now traverse the digits
        
        getCombos(0, nums, n, res, "");
        return res;

    }
};