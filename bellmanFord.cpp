/*
Just like Dijkstra's algo but is more time consuming and can handle negative cycles.
Only Applicable for Directed Graph.
*/

class Solution
{
public:
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   S: source vertex to start traversing graph with
     *   V: number of vertices
     */
    vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
    {
        vector<int> dist(V, 1e8);
        dist[S] = 0;
        for (int i = 0; i < V - 1; i++)
        {
            for (auto it : edges)
            {
                int src = it[0];
                int dest = it[1];
                int edgWt = it[2];

                if (dist[src] != 1e8 && dist[src] + edgWt < dist[dest])
                {
                    // this process is called relaxation where we try to minimize the dist
                    // to reach a particular node by following the rules
                    dist[dest] = dist[src] + edgWt;
                }
            }
        }
        // In V-1 times all the nodes will be assigned the shortest distance to reach them
        // form the source, but if there is a negative cycle then even after V-1 times
        // distance will still get shorter and from this we can find if there is a
        // negative cycle.
        for (auto it : edges)
        {
            int src = it[0];
            int dest = it[1];
            int edgWt = it[2];
            // means there is a negative edge cycle
            if (dist[src] != 1e8 && dist[src] + edgWt < dist[dest]) return {-1};
        }

        return dist;
    }
};