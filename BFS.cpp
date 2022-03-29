#include<bits/stdc++.h>
using namespace std;
int main()
{
    int no_edge,no_node;
    cin>>no_edge>>no_node;
    vector<vector<int>>edges_list(no_node+1);
    for(int i = 0 ; i<no_edge;i++)
    {
        int a,b;
        cin>>a>>b;
        edges_list[a].push_back(b);
        edges_list[b].push_back(a);
    }
    queue<int>q;
    vector<int>vis(no_node+1,-1);
    q.push(1);
    vis[1]=0;
    while(!q.empty())
    {
        int top=q.front();
        q.pop();
        for(auto to : edges_list[top])
        {
            if(vis[to]==-1)
            {
                vis[to]=vis[top]+1;
                q.push(to);
            }
        }
    }
    for(int i=1;i<=no_node;i++)
    {
        cout<<"node "<<i<<" >> "<<vis[i]<<endl;  // node level
    }
    
}
