/*

1. first possiblity is that there is either no element in ans to comapre or there is no
merging going on, in that case we will have to 

*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // sort the intervals on the basis of start time
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        // get the very first interval so that we can start comparing
        vector<int>first = intervals[0];
        for(int i = 1; i < intervals.size(); i++)
        {
            if(intervals[i][0] < first[1])
            {
                // implies merging is possible
                int start = min(first[0], intervals[i][0]);
                int end = max(intervals[i][1], first[1]);
                ans.push_back({start, end});
                
            }
            first.clear();
            first = ans[i];
        }
        return ans;
    }
};