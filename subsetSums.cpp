class Solution
{
public:

    void getSubsets(int idx, int sum , vector<int>&ans, vector<int>&arr, int N)
    {
        //base case
        if(idx == N)
        {
            ans.push_back(sum);
        }

        // you can either pick the question
        getSubsets(idx+1, sum+arr[idx], ans, arr, N);
        //or leave the element and move on
        getSubsets(idx+1, sum, ans, arr, N);
    }

    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        getSubsets(0, 0, ans, arr, N);
        return ans;
    }
};