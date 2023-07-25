class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), j;
        int left[n], right[n];
        vector<int>res;
        left[0] = 1;
        right[n-1] = 1;
        for(int i = 1; i < n; i++)
        {
            j = (n-1)-i; // will reduce by each time
            left[i] = left[i-1]*nums[i-1];
            right[j] = right[j+1]*nums[j+1];
        }
        // once calculated then we just have to multiple the two
        for(int i = 0; i < n; i++)
        {
            res.push_back(left[i]*right[i]);
        }
        return res;
    }
};