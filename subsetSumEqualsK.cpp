#include <bits/stdc++.h> 

bool subsetSum(int idx, int k, vector<int>&arr, vector<vector<int>>&dp)
{
    if(k == 0) return true;
    if(i == 0) return (arr[0]==k);
    if(dp[idx][k] != -1) return dp[idx][k];
    // pick and not pick
    bool notPick = subsetSum(idx-1, k, arr, dp);
    bool pick = false;
    if(arr[idx] <= k)
    {
        pick = subsetSum(idx-1, k-arr[idx], arr, dp);
    }
    return dp[idx][k] = pick | notPick;

}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>>dp(n, vector<int>(k+1, -1));
    return subsetSum(n-1, k, arr, dp);

}
