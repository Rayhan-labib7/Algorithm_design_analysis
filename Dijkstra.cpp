#include<bits/stdc++.h>
using namespace std;
int main()
{
    //Labib
    int num_node, num_edge;
    cin>>num_node>>num_edge;
    int u,v,w;
    vector<vector<pair<int,int>>>graph(num_node+1);
    for(int i=0;i<num_edge;i++)
    {
         cin>>u>>v>>w;
         graph[u].push_back({v,w});
    }
    vector<int>distance(num_node+1,INT_MAX);
    distance[1]=0;
    priority_queue<pair<int,int>>pq;
    pq.push({0,1});//{cost,node}
    while (!pq.empty())
    {
        pair<int,int>top=pq.top();pq.pop();
        int cost=-1*top.first,curr_node=top.second;
        for(auto to : graph[curr_node])
        {
            if(distance[to.first]>cost+to.second)
            {
               distance[to.first]=cost+to.second;
               pq.push({-1*distance[to.first],to.first});
            }
        }
    }
    cout<<distance[num_node]<<endl; 
}
