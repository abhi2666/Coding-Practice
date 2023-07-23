/*
Input: nums = [1,2,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0 
[2], range = 2 - 2 = 0
[3], range = 3 - 3 = 0
[1,2], range = 2 - 1 = 1
[2,3], range = 3 - 2 = 1
[1,2,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.
*/

// Brute Force 
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int mx, mn, sum = 0;
        for(int i = 0; i < n; i++)
        {
            mx = nums[i];
            mn = nums[i];
            for(int j = i; j < n; j++)
            {
                mx = max(mx, nums[j]);
                mn = min(mn, nums[j]);
                sum += (mx - mn);
            }
        }
        return sum;
    }
};