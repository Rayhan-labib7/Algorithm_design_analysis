const int MX = 100002;
const int LOG = 14;
vector<int>adj[MX];
int up[MX][LOG];
int depth[MX];
void dfs(int node)
{
    for(auto child : adj[node])
    {
       depth[child]=depth[node]+1;
       dfs(child);
    }
}
void spare_table(int N)
{
  for(int j = 1; j < LOG; j++)
  {
    for(int i = 1; i <= N; i++)
    {
       if(up[i][j-1] != -1)
       {
         up[i][j] = up[up[i][j-1]][j-1];
       }
       
     }
  }
}
int kth(int a, int k){

	for(int i = 0; i <= LOG; i++){
		if(k & (1 << i))
			a = up[a][i];
	}
	return a;
}
int get_lca(int a, int b)
  {
      if(depth[a]<depth[b])
      {
        swap(a,b);
      }
      int k=depth[a]-depth[b];
      for(int j=LOG-1;j>=0;j--)
      {
        if(k&(1<<j))
        {
          a = up[a][j]; 
        }
      }
      if(a==b){
        return a;
      }
      for(int j=LOG-1;j>=0;j--)
      {
        if(up[a][j]!=up[b][j]){
          a=up[a][j];
          b=up[b][j];
        }
      }
      return up[a][0];
  }
