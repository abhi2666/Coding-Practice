#include <bits/stdc++.h>
using namespace std;
/*
Input:
[2,4,3]
Output: 
14
Explanation: 
First connect 2 and 3 to 5 and cost 5; then connect 5 and 4 to 9; total cost is 14
get the smallest sum possible to connect all the sticks(array values).
*/
class Solution
{
public:
    int minimumCost(vector<int> &sticks)
    {
        sort(sticks.begin(), sticks.end());
        int sum = 0, answer = 0;
        for(int i = 0; i < sticks.size(); ){
            if(i == 0)
            {
                sum += (sticks[i] + sticks[i + 1]);
                i +=2;
            }
            else{
                sum += sticks[i];
                i++; 
            }
            answer += sum;
        }
        return answer;
    }
};

int main()
{
    vector<int> sticks = {5, 8, 3, 1};
    Solution s;
    cout << s.minimumCost(sticks) << endl;
    return 0;
}