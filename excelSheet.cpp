/*
Example 1:

Input: columnTitle = "A"
Output: 1
Example 2:

Input: columnTitle = "AB"
Output: 28
Example 3:

Input: columnTitle = "ZY"
Output: 701
*/

// class Solution {
// public:
//     int titleToNumber(string ct) {
//         int ans = 0;
//         int n = ct.size();
//         for(int i = 0; i < n-1; i++)
//         {
//             ans +=  26*(ct[i] - 64);
//         }
//         ans += (ct[n-1] - 64);

//         return ans;
//     }
// };

class Solution {
public:
    int titleToNumber(string ct) {
        int ans = 0;
        for(auto ch : ct)
        {
            int val = ch-64;
            ans = ans*26 + val;
        }

        return ans;
    }
};