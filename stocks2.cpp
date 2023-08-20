class Solution {
public:
    int val = INT_MIN;
    int sum(int idx, vector<int>&profit)
    {
        if(idx < profit.size())
        {
            
        }

        int take = profit[idx] + sum(idx + 1, profit);
        int nottake = sum(idx + 1, profit);
        val = max(take, nottake);
        return val;
    }

    int maxProfit(vector<int>& prices) {
        // 7, 1, 5, 3, 6, 4
        return sum(0, prices);

    }
};