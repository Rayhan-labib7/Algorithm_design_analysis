class BFS
{
  public:
  int n,u,v;
  vector<vector<int>>adj;
  vector<bool>vis;
  vector<int>color;
  BFS(int _n)
  {
     n=_n;
     adj.resize(n+1);
     color.resize(n+1);
     vis.resize(n+1);
  }
  void input_read(int _u,int _v)
  {
    u=_u;
    v=_v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  bool bfs(int node)
  {
    queue<int>q;
    q.push(node);
    vis[node]=true;
    color[node]=0;
    while (!q.empty())
    {
        int top = q.front();
        q.pop();
        for(auto child:adj[top])
        {
           if(!vis[child]){
            vis[child]=true;
            q.push(child);
            color[child]=(color[top]^1);
           }
           else if(color[top]==color[child]){
             return false;
           }

        }
    }
    return true;
    
  }
};
