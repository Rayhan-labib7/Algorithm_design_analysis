#include<bits/stdc++.h>
using namespace std;
void prims(vector<vector<pair<int,int>>>&graph,int num_node)
{
   
    vector<int>dist(num_node+1,INT_MAX),vis(num_node+1);
    dist[1]=0;
    priority_queue<pair<int,int>>pq;
    pq.push({0,1});
    int total_cost=0;
    while(!pq.empty())
    {

        pair<int,int>top=pq.top();pq.pop();
        int cost=-1*top.first,node=top.second;
        if(vis[node])
        {
            continue;
        }
        vis[node]=1;
        total_cost+=cost;
        for(auto to : graph[node])
        {
            if(vis[to.first]==0)
            {
                pq.push({-1*to.second,to.first});
            }
        }
    }
    cout<<total_cost<<endl;
}
int main()
{
    int num_node,num_edge;
    cin>>num_node>>num_edge;
    int u,v,w;
    vector<vector<pair<int,int>>>graph(num_node+1);
    for(int i=0;i<num_edge;i++)
    {
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }
    prims(graph,num_node);
}
