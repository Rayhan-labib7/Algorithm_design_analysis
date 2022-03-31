#include<bits/stdc++.h>
using namespace std;
struct node{
    int parent;
    int rank;
};
vector<node>dsuf;
int find(int v)
{
     if(dsuf[v].parent==-1)
     {
         return v;
     }
     return dsuf[v].parent=find(dsuf[v].parent);
}
void union_op(int fromP,int toP)
{
    if(dsuf[fromP].rank>dsuf[toP].rank)
    {
        dsuf[toP].parent=fromP;
    }
    else if(dsuf[fromP].rank<dsuf[toP].rank)
    {
        dsuf[fromP].parent=toP;
    }
    else 
    {
        dsuf[fromP].parent=toP;
        dsuf[toP].rank+=1;
    }
}
bool isCyclic(vector<pair<int,int>>& edge_list)
{
    for(auto p : edge_list)
    {
        int fromP=find(p.first);
        int toP=find(p.second);
        if(fromP==toP)
        {
           return true;
        }
        union_op(fromP,toP);
    }
    return false;
}
int main()
{
   int edge;
   int vertices;
   cin>>edge>>vertices;
   dsuf.resize(vertices);
   for(int i=0;i<vertices;i++)
   {
       dsuf[i].parent=-1;
       dsuf[i].rank=0;
   }
   vector<pair<int,int>>edge_list;
   for(int i=0;i<edge;i++)
   {
       int from,to;
       cin>>from>>to;
       edge_list.push_back({from,to});
   }
   if(isCyclic(edge_list))
   {
       cout<<"True"<<endl;
   }
   else{
       cout<<"False"<<endl;
   }
   return 0;
}
