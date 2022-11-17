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
.............
    
    
    
    struct Node
{
    ll nd,cost;
    Node(ll a,ll b)
    {
        nd=a;
        cost=b;
    }
};
struct Edge
{
    ll v,w;
    Edge(ll a,ll b)
    {
        v=a;
        w=b;
    }
};
bool operator<(Node a,Node b)
{
    return a.cost>b.cost;
}
priority_queue<Node>pq;
vector<Edge>graph[Max];
ll dis[Max],parent[Max];
ll node;

void dijkstra()
{
    for(int i=1;i<=node;i++)
    {
        dis[i]=inf;
    }
    dis[1]=0;
    pq.push(Node(1,0));
    while (!pq.empty())
    {
        Node u=pq.top();
        pq.pop();
        if(u.cost!=dis[u.nd]) continue;
        for(auto child:graph[u.nd])
        {
            Edge e=child;
            if(dis[e.v]>u.cost+e.w)
            {
                dis[e.v]=u.cost+e.w;
                pq.push(Node(e.v,dis[e.v]));
                parent[e.v]=u.nd;
            }
        }
    }
    
}
...............
    
                                               

#include <bits/stdc++.h>

#define     ll                                 long long int   

#define     ll_in1(a)                          cin>>a

#define     ll_in2(a,b)                        cin>>a>>b

#define     ll_in3(a,b,c)                      cin>>a>>b>>c

#define     take_vector_int(x,o,n)             for(int i=o;i<=n;i++){cin>>x[i];}    

#define     srt(v)                             sort(v.begin(),v.end());

#define     rsrt(v)                            reverse(v.begin(),v.end())

#define     gcd(a, b)                          __gcd(a, b)

#define     vi                                 vector<int>

#define     vll                                vector<ll>

#define     endl                               '\n'

#define     yes                                cout<<"YES"<<endl

#define     no                                 cout<<"NO"<<endl

#define mem(a,i)            memset(a, i, sizeof(a))

#define     Labib                              ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod   1000003                 
using namespace std;
const int N=1e5+10;
const ll inf=1e18;
vector<pair<int,int>>g[N];
int parent[N],n;
ll dijkstra(int source)
{
    vector<ll>vis(N,0);
    vector<ll>dist(N,inf);
    set<pair<ll,ll>>st;
    st.insert({0,source});
    dist[source]=0;

    while (st.size()>0)
    {
        auto node=*st.begin();
        ll  v=node.second;
        ll  dst=node.first;
        st.erase(st.begin());
        for(auto child:g[v])
        {
            ll child_v=child.first;
            ll wt=child.second;
            if(wt+dist[v]<dist[child_v])
            {
                dist[child_v]=wt+dist[v];
                st.insert({dist[child_v],child_v});
                parent[child_v]=v;
            }
        }
    }
    return dist[n];
    
}


int main()
{
   Labib
   ll m;
   cin>>n>>m;
   for(int i=0;i<m;i++)
   {
    ll u,v,w;
    cin>>u>>v>>w;
    g[u].push_back({v,w});
    g[v].push_back({u,w});
   }
   ll ans=dijkstra(1);
   if(ans==inf)
   {
    cout<<-1<<endl;
    return 0;
   }
   else
   {
       vector<int>path;
       ll x=n;
       while (x!=1)
       {
        path.push_back(x);
        x=parent[x];
       }
       path.push_back(1);
       for(int i=path.size()-1;i>=0;i--)
       {
         cout<<path[i]<<" ";
       }
       cout<<endl;
   }

    return 0;
}
.............
