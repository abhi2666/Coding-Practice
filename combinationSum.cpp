/**
 * Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Repeated element picking is allowed so while picking the element we have to keep in mind that 
not to increase the index.
if you don't pick the element then move for the next element
 * 
*/

class Solution {
public:

    void findSum(int idx, vector<int>&candidates, int target, vector<vector<int>>&ans, vector<int>&ds)
    {
        //base case
        if(idx == candidates.size())
        {
            if(target == 0)
            {
                // you got one subset
                ans.push_back(ds);
                
            }
            return;
        }

        // you can either pick the element and stay there
        // but first check if that element is less than target or not
        if(candidates[idx] <= target)
        {
            ds.push_back(cadidates[idx]);
            findSum(idx, candidates, target-candidates[idx], ans, ds);
            ds.pop_back();

            findSum(idx, candidates, target, ans, ds);

        }
        

    }   
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findSum(0, candidates, target, ans, ds);
        return ans;
    }
};