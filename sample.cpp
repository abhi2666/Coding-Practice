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

    queue<int> q; // will store the elements
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0) q.push(i);
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
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
    return topo;
}

};