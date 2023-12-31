/*
Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].



Approach --> store the elements with their frequency into the map and sort it in decreasing 
order of frequency. Then one by one pick element and put it into the vector.
If any element remain then put it also at the very end.
*/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //preparing adjaceny list
        vector<int> adj[numCourses];
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        // apply topo sort on the data above
        int indegree[numCourses];
        for(int i = 0; i < numCourses; i++){
            indegree[i] = 0;
        } 
        for(int i = 0; i < numCourses; i++)
        {
            for(auto it : adj[i])
            {
                indegree[it]++;
            }
        }

        queue<int>q;
        vector<int>topo;
        for(int i = 0; i < numCourses; i++)
        {
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int data = q.front(); // data represent the index with 0 indegree
            q.pop();
            topo.push_back(data);

            for(auto it : adj[data]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        // if there is any cycle then return {}.
        if(topo.size() == numCourses) return topo;
        else return {};
    }
};