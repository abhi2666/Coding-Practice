/*
Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
*/


class Solution {
public:

    void getSubsets(int idx, vector<vector<int>>&result, vector<int>&inter, vector<int>&nums)
    {
        // do not pick the elements which has already been picked
        
        //pick the element
        result.push_back(inter);
        for(int i = idx; i < nums.size(); i++)
        {
            // check if there is no duplicate, then only pick the element
            if(i != idx && nums[i] == nums[i - 1]) continue;
            // if current element is not duplicate
            inter.push_back(nums[i]);
            getSubsets(idx, result, inter, nums);
            inter.pop_back();
        }

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> inter;
        sort(nums.begin(), nums.end());
        getSubsets(0, result, inter, nums);

        return result;

    }
};