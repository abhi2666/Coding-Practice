
// Memoisation
//  class Solution {
//  public:

//     int getCombos(int amt, int idx, vector<int>& coins, vector<vector<int>>&dp)
//     {
//         if(amt == 0) return 1;
//         if(idx < 0) return 0;

//         // you can either pick the current element or move backward
//         if(dp[idx][amt]) return dp[idx][amt];
//         int pick = 0;
//         if(coins[idx] <= amt)
//         {
//             pick = getCombos(amt-coins[idx], idx, coins, dp);
//         }
//         int notPick = getCombos(amt, idx-1, coins, dp);

//         return dp[idx][amt] = pick + notPick;
//     }
//     int change(int amount, vector<int>& coins) {

//         vector<vector<int>>dp(coins.size(), vector<int>(amount+1, 0));
//         return getCombos(amount, coins.size()-1, coins, dp);
//     }
// };

// Tabulation
class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {

        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, 0));

        // base case
        for (int i = 0; i < coins.size(); i++)
        {
            dp[i][0] = 1;
        }

        for (int i = 0; i < coins.size(); i++)
        {
            for (int j = 1; j < amount + 1; j++)
            {
                int pick = 0;
                if (coins[i] <= j)
                {
                    pick = dp[i][j - coins[i]];
                }
                int notPick = i > 0 ? dp[i-1][j] : 0; 

                dp[i][j] = pick + notPick;
            }
        }
        return dp[coins.size() - 1][amount];
    }
};