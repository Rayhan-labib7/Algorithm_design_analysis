#include<bits/stdc++.h>
using namespace std;
vector<int>dsuf;
int find(int v)
{
    if(dsuf[v]==-1)
    {
        return v;
    }
    return find(dsuf[v]);
}
void union_op(int fromP,int top)
{
    dsuf[fromP]=top;
}
bool isCyclic(vector<pair<int,int>>& edge_list)
{
    for(auto p : edge_list)
    {
        int fromP = find(p.first); //FIND absolute parent of subset
        int toP   = find(p.second);
        if(fromP == toP)
        {
            return true;
        }
        // union operation----
        union_op(fromP,toP);

    }
}
int main()
{
    int E; //no of edges
    int V; //no of vertices (0 to n=v-1)
    cin>>E>>V;
    dsuf.resize(V,-1); //Mark all vertices as separate subset with only 1 element
    vector<pair<int,int>>edge_list;
    for(int i=0;i<E;i++)
    {
        int from,to;
        cin>>from>>to;
        edge_list.push_back({from,to});
    }
    if(isCyclic(edge_list))
    {
        cout<<"TRUE"<<endl;
    }
    else
    {
        cout<<"FALSE"<<endl;
    }
}
