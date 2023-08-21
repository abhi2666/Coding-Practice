/*
Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
/*
Approach --> using a prefix sum approach....we will find prefixSum - k in the map of prefix sum and
their occurence and with this will find the subarrays with given sum.
*/
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unorderd_map<int, int> mp;
        mp[0] = 1; // in case of prefixSum - k = 0 in this case we will use this zero
        int prefixSum = 0, cnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            prefixSum += nums[i];
            cnt += mp[prefixSum - k];
            mp[prefixSum - k]++;
        }

        return cnt;
    }
};