class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // nums = [1,7,3,6,5,6]
        int n = nums.size();
        vector<int>prefix(n, 0), suffix(n, 0);
        prefix[0] = suffix[0] = 0;
        
        for(int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i-1] + nums[i-1] ;
        }
        for(int i = n - 2; i >= 0; i--)
        {
            suffix[i] = nums[i + 1] + suffix[i+1];
        }
        
        for(int i = 0 ; i < n; i++)
        {
            if(prefix[i] == suffix[i]) return i;
        }
        return -1;

    }
};