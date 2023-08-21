class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        unordered_map<int, int>mp; // element and index
        int prefixSum = 0, maxLen = 0;
        for(int i = 0; i < A.size(); i++)
        {
            prefixSum += A[i];
            if(prefixSum == 0) 
            {
                // you got an subarray directly from start
                maxLen = i + 1;
            }
            if(mp.find(prefixSum) != mp.end())
            {
                // means this sum has already occured before and its index is stored in map
                maxLen = max(maxLen, i - mp[prefixSum]);
                // we will not update its index because we want the largest possible sum
            }
            else {
                // makes its entry into map
                mp[prefixSum] = i;
            }
        }
        return maxLen;
    }
};