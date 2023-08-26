/*
Approach --> using a greedy approach by sorting the vectors based on the second value/
This can be done easily by using a modified sort function.
After that we will check each interval one by one and for valid interval we will inc the counter.

TC - O(nlogn)
SC - O(1)
*/

class Solution
{
public:
    int findLongestChain(vector<vector<int>> &pairs)
    {

        sort(pairs.begin(), pairs.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[1] < b[1]; });
        int ans = 0, currInterval = INT_MIN;
        for (auto it : pairs)
        {
            if (currInterval < it[0])
            {
                currInterval = it[1]; // interval will get updated automatically
                ans++;
            }
        }

        return ans;
    }
};