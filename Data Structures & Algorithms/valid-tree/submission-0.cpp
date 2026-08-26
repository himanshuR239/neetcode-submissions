class Solution {
public:
    bool cycle(int node, int parent, vector<bool> &vis, vector<vector<int>> &adj){
        vis[node] = true;

        for(int ngbr : adj[node]){
            if(!vis[ngbr]){
                if(cycle(ngbr, node, vis, adj)) return true;
            }
            else if(ngbr != parent) return true;
        }

        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1) return false;
        vector<vector<int>> adj(n);

        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<bool> vis(n, false);

        if(cycle(0, -1, vis, adj)) return false;

        for(bool v : vis){
            if(!v) return false;
        }

        return true;
    }
};
