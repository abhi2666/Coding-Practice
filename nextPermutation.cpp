/*
A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].

Approach --> ...

*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // find the first element which is smaller than its right element
        int idx = -1;
        int n = nums.size();
        for(int i = n-2; i >= 0; i--)
        {   
            if(nums[i] < nums[i + 1]){
                idx = i;
                break;
            }
        }
        if(idx == -1) return reverse(nums.begin(), nums.end());

        for(int i = n-1; i >= idx; i--)
        {
            if(nums[i] > nums[idx]){
                swap(nums[i], nums[idx]);
                break;
            }

        }
        reverse(nums.begin()+idx, nums.end());
    }
};