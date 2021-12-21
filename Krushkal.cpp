#include<bits/stdc++.h>
using namespace std;
#define M 100
int parent[M];
int num_element[M];
int Find_parent(int node)
{
    if(node==parent[node])
    {
        return node;
    }
    else
    return parent[node]=Find_parent(parent[node]);
}
void Union(int u,int v)
{
    if(num_element[u]>=num_element[v])
    {
        parent[v]=u;
        num_element[u]+=num_element[v];
    }
    else
    {
        parent[u]=v;
        num_element[v]+=num_element[u];
    }
    
}
void Set(int node)
{
    for(int i=0;i<node;i++)
    {
        parent[i]=i;
        num_element[i]=1;
    }
}
int main()
{
   int num_node,num_edge;
   cin>>num_node>>num_edge;
   Set(num_node);
   vector<pair<int,pair<int,int>>>edges(num_edge);
   int u,v,w;
   for(int i=0;i<num_edge;i++)
   {
       cin>>u>>v>>w;
       edges[i]={w,{u,v}};
   }
   sort(edges.begin(),edges.end());
   int total_cost=0;
   for(int i=0;i<num_edge;i++)
   {
       w=edges[i].first;
       u=edges[i].second.first;
       v=edges[i].second.second;
       int parent_of_u=Find_parent(u);
       int parent_of_v=Find_parent(v);
   
   if(parent_of_u!=parent_of_v)
   {
       total_cost+=w;
       cout<<"Add edge >> "<<u<<" "<<v<<" Cost :"<<total_cost<<endl;
       Union(parent_of_u,parent_of_v);
       
   }
   }

}
