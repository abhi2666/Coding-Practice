class Solution {
public:
    bool dfs(int i, vector<int>& vis, vector<vector<int>>& adj, vector<vector<int>>& prerequisites, stack<int>& st){
        vis[i] = 1;
        for(auto it : adj[i]){
            if (vis[it] == 0) {
                if (dfs(it, vis, adj, prerequisites, st)) {
                    return true;
                }
            } else if (vis[it] == 1) {
                return true; // Cycle detected
            }
        }
        vis[i] = 2;
        st.push(i);
        return false;
    }

    vector<int> findOrder(int V, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(V);
        vector<int> vis(V, 0);

        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        stack<int> st;
        for(int i=0; i<V; i++){
            if(vis[i] == 0){
                if (dfs(i, vis, adj, prerequisites, st)) {
                    return {}; // Cycle detected, return an empty vector
                }
            }
        }

        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};