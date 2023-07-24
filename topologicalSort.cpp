/*
To Lineraly order the nodes of a graph such that for a edge between u and v, u always comes
before v in order.

Can be implemented using BFS or DFS (here we will use BFS ALGORITHM)
*/

class Solution
{
public:
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        int indegree[V] = {0};
        // traverse the adjacency list and fill the indegree
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                indegree[it]++;
            }
        }

        queue<int> q;
        // will store the elements
        /// put all the elements that have indeg == 0 into queue so we can start with the bfs

        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> topo;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            // for this element..check for elements that it is providing an edge to.
            for (auto it : adj[node])
            {
                indegree[it]--;
                if (indegree == 0)
                {
                    q.push(it);
                }
            }
        }
        return topo;
    }
};