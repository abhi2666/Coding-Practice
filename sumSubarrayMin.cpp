/*
Find all the subarrays and then from all the subarrys find minimum element and then
sum all those and return
*/

// NOT GIVING CORRECT OUTPUT
class Solution {
public:
    int sum = 0;

    int findMin(vector<int>ds)
    {
        int mini = INT_MAX;
        for(int i : ds)
        {
            mini = min(mini, i);
        }
        return mini;
    }

    void getSubarray(int idx, vector<int>&ds,  vector<int>&arr)
    {
        //base case
        if(idx == arr.size())
        {
            // one subarray is ready
            sum += findMin(ds);
            return;
        }

        // you can either pick an element or you can leave it and move forward
        ds.push_back(arr[idx]);
        getSubarray(idx+1, ds, arr);
        ds.pop_back();
        getSubarray(idx+1, ds, arr);
    }

    int sumSubarrayMins(vector<int>& arr) {
        getSubarray(0, arr);
        return sum;
    }
};