class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        
        // for each interval check if there is any merging or if not then we will have to
        // create a new entry in the ans vector..
        sort(intervals.begin(), intervals.end());

        for(int i = 0; i < intervals.size(); i++)
        {
            if(ans.empty() || ans.back()[1] < interval[i][0]){
                // no merging is possible create a new entry
                ans.push_back(interval[i]);
            }
            else{
                // if there is any merging then
                ans.back()[1] = max(ans.back()[1], interval[i][1]);
            }
        }
        return ans;
    }
};