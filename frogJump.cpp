/*
frog starting from start has to reach end index...and each time it can move i + 1 or i + 2 th 
positions. And for each jump it will cost the frog a[j - 1] - a[i - 1] when jumping from ith to 
jth index.
*/

// Top Down Recursive Approach
// #include <bits/stdc++.h> 
// int minCost(int idx, vector<int>&dp vector<int>&heights)
// {
//     if(idx == 0)
//         return 0;
    
//     if(dp[idx]) return dp[idx];
//     int moveOne = minCost(idx-1, heights) + abs(heights[idx] - heights[idx-1]);
//     int moveTwo = INT_MAX;
//     if(idx > 1)
//         moveTwo = minCost(idx - 2, heights) + abs(heights[idx] - heights[idx - 2]);
//     return dp[idx] = min(moveOne, moveTwo);
// }

// int frogJump(int n, vector<int> &heights)
// {
//     vector<int>dp(n, 0);
//     return minCost(n-1, dp, heights);
// }

// Bottom up iterative approach --> almost the same as the recursive approach but now we will 
// move from starting i.e., 0 index to n - 1 and from there will calculate the values
// Advantage --> remove the recursive stack space
#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights)
{
    vector<int>dp(n, 0);
    dp[0] = 0;
    for(int i = 1; i < n; i++)
    {
        int moveOne = abs(heights[i] - heights[i - 1]) + dp[i-1];
        int moveTwo = INT_MAX;
        if(idx > 1)
            moveTwo = abs(heights[i] - heights[i - 2]) + dp[i - 2];
        dp[i] = min(moveOne, moveTwo);
    }
    return dp[n-1];
}