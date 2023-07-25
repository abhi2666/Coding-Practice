/*
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take.
To take course 1 you should have finished course 0. So it is possible.

// we can apply topo sort to arrange the order and if in any case
        // topo.size() != n it means that there is a cycle in the graph and
        // hence we cannot process it.
*/

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
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
        // check if the topo sort was successfull and there was no graph
        if(topo.size() == numCourses) return true;
        else return false;
    }
};