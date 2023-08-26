class Solution
{
public:
    int houseRobber(vector<int> &nums)
    {
        int prev1, prev2 = 0, curr;
        prev1 = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            //pick the element
            int take = nums[i] + prev2;
            //leave it 
            int notTake = 0 + prev1;

            curr = max(take, notTake);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }

    int rob(vector<int> &nums)
    {
        
        vector<int> t1, t2;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (i != 0)
                t1.push_back(nums[i]);
            if (i != n - 1)
                t2.push_back(nums[i]);
        }
        // with both these we will implement the typical house robber problem
        int ans = max(houseRobber(t1), houseRobber(t2));
        return ans;
    }
};

/*
class Solution{
public:
    int rob(vector<int> &nums)
    {
        int prev1, prev2 = 0, curr;
        prev1 = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            //pick the element
            int take = nums[i] + prev2;
            //leave it 
            int notTake = 0 + prev1;

            curr = max(take, notTake);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }

};
*/