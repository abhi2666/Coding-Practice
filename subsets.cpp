/*
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Approach --> a recursive style solution would be best for this case.
*/
class Solution
{
public:
    void getSubsets(int index, vector<vector<int>> &ans, vector<int> &ds, vector<int> &nums)
    {
        if (index == nums.size())
        {
            ans.push_back(ds);
            return;
        }

        // can pick or not pick the current element

        ds.push_back(nums[index]);
        getSubsets(index + 1, ans, ds, nums);
        ds.pop_back();
        getSubsets(index + 1, ans, ds, nums);
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        getSubsets(0, ans, ds, nums);

        return ans;
    }
};