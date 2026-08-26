class Solution {
public:
    void dfs(int node, vector<bool> &vis, vector<vector<int>> &adj){
        vis[node] = true;

        for(int ngbr : adj[node]){
            if(!vis[ngbr]){
                dfs(ngbr, vis, adj);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<bool> vis(n, false);
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                cnt++;
                dfs(i, vis, adj);
            }
        }

        return cnt;
    }
};
