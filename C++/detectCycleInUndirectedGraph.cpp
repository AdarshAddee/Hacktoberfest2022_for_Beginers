  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int v, int par, vector<int> g[], vector<int> &vis)
    {
        vis[v]=1;
        for(auto it: g[v])
        {
            if(vis[it]==0)
            {
                if(dfs(it, v, g, vis)==true)
                return true;
            }
            else if(it!=par)
            {
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        for(int i=0; i<V; i++)
        {
            if(vis[i]==0)
            {
                if(dfs(i, -1, adj, vis))
                    return true;
            }
        }
        return false;
    }
};