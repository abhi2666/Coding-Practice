/*

Memoisation Approach
*/

class Solution {
public:

    int jumps(int idx, vector<int>&nums, vector<int>&dp)
    {
        if(idx >= nums.size()-1) return 0;
        if(dp[idx] != 0) return dp[idx];
        int mini = INT_MAX;
        for(int i = 1; i <= nums[idx]; i++)
        {
            int totalJumps = 1 + jumps(i + idx, nums);
            mini = min(mini, totalJumps);
        } 

        return dp[idx] = mini;
    }

    int jump(vector<int>& nums) {
        vector<int>dp(nums.size(), 0);
        return jumps(0, nums, dp);
    }
};
