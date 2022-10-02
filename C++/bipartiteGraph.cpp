class Solution{
    public:
    bool check(int node, int color, vector<int> adj[], vector<int> &col)
    {
        col[node]=color;
        for(auto it: adj[node])
        {
            if(col[it]==-1)
            {
                if(check(it, !color, adj, col)==false)
                    return false;
            }
            else if(col[it]==color)
            {
                return false;
            }
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> col(V, -1);
	    for(int i=0; i<V; i++)
	    {
	        if(col[i]==-1)
	        {
	            if(check(i, 0, adj, col)==false)
	                return false;
	        }
	    }
	    return true;
	}

};