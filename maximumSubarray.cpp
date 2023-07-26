/*
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.

Approach --> kadane's Algo
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = 0, sum = INT_MIN;
        for(int i : nums){
            currSum += i;
            sum = max(currSum, sum);
            if(currSum < 0){
                currSum = 0;
            }
        }
        return sum;
    }
};