class DFS
{
    public:
    int n;
    vector<vector<int>>graph;
    vector<bool>vis;
    bool check=false;
    int edge_cnt=0;
    int node_cnt=0;
    DFS(int _n)
    {
        n=_n;
        graph.resize(n+1);
        vis.resize(n+1,false);
    }
    
    void create_graph(int u,int v)
    {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    void dfs(int node,int parent)
    {
        vis[node]=true;
        for(auto child:graph[node])
        {
          if(!vis[child]){
            dfs(child,node);
          }
          
        }
    }
};
