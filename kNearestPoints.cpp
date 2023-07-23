/*
Input: points = [[1,3],[-2,2]], k = 1
Output: [[-2,2]]
Explanation:
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].
*/

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        vector<vector<int>>ans;
        priority_queue<int>pq; // will store the distances 
        int j = 0;
        for(auto i : points)
        {
            float data = (i[0]*i[0] + i[1]*i[1]);
            pq.push({-1*points, i});
        }
        // now put all the elements of pq into an array
        while(k--)
        {   
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }   
        return ans;
    }
};