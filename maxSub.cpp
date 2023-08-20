/*
[2,3,-2,4]
                        (3, 0)
                    (2, 4)    (2, 0)
                ()
*/


// Below code will work for subsequence not for subarray
// class Solution {
// public:
//     int getProduct(int idx, vector<int>&nums)
//     {
//         if(idx < 0) return 0;

//         int pick = nums[idx] * getProduct(idx - 1, nums);
//         int notPick = getProduct(idx - 1, nums);

//         return max(pick, notPick);

//     }

//     int maxProduct(vector<int>& nums) {
//         int n = nums.size();
//         return getProduct(n, nums);
//     }
// };

/*
for subarray we can't skip elements in between
*/

class Solution {
public:

    int getProduct(int idx, int prod, vector<int>&nums){
        if(idx == 0) return nums[0];

        return max(getProduct(idx - 1, prod * nums[idx], nums), getProduct(idx - 1, 1, nums));
    }
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        return getProduct(n-1, 1, nums);
    }
};
