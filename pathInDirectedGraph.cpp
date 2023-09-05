int Solution::solve(int A, vector<vector<int> > &B) {

    vector<int>adj[A+1];
    int n = B.size();
    for(int i = 0; i < n; i++)
    {
        adj[B[i][0]].push_back(B[i][1]); // directed graph
    }

    vector<int>vis(A+1, 0);
    dist[1] = 0;
    queue<int>q; // node
    q.push(1);
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for(auto neighbour : B[node])
        {
            if(vis[neighbour] == 0)
            {
                q.push(neighbour);
                vis[neighbour] = 1; 
            }
        }
    }
    if(vis[A] == 1) return 1;
    else return 0;
}
