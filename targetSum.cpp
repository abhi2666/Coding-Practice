
/*

Recursion approach
*/

// class Solution {
// public:
    
//     int targetSum(int idx, int sum, vector<int>&nums, int target, vector<vector<int>>&dp)
//     {
//         if(idx == nums.size()){
//             if(sum == target) return 1;
//             else return 0;
//         }
//         if(dp[idx][sum]) return dp[idx][sum];
//         int add = targetSum(idx+1, sum-nums[idx], nums, target, dp);
//         int sub = targetSum(idx+1, sum+nums[idx], nums, target, dp);

//         dp[idx][sum] = add + sub;
//         return dp[idx][sum];
        
//     }

//     int findTargetSumWays(vector<int>& nums, int target) {
//         vector<vector<int>>dp(nums.size(), vector<int>(target+1, 0));
//         return targetSum(0, 0, nums, target, dp);
//     }
// };


class Solution {
public:
    int targetSum(int idx, int sum, vector<int>& nums, int target, vector<vector<int>>& dp) {
        if (idx == nums.size()) {
            if (sum == target) return 1;
            else return 0;
        }
        if (dp[idx][sum] != -1) return dp[idx][sum];
        
        int add = targetSum(idx + 1, sum + nums[idx], nums, target, dp);
        int sub = targetSum(idx + 1, sum - nums[idx], nums, target, dp);

        dp[idx][sum] = add + sub;
        return dp[idx][sum];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0); // Calculate the total sum of the array
        // sum can range from - sum(nums) to +sum(nums) resulting in 2*sum + 1 of size required
        // for the sum part of the dp array..
        int dpSize = sum * 2 + 1; // Size of the DP array
        
        vector<vector<int>> dp(nums.size(), vector<int>(dpSize, -1));
        return targetSum(0, sum, nums, target + sum, dp); // Adjust target and sum for zero-centered DP
    }
};

