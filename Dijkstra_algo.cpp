                                           

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

const int dx[] = {+1,-1,+0,+0}; ///Rock's Move

const int dy[] = {+0,+0,+1,-1}; ///Rock's Move


const       ll                                 INF = 1122334455667788990;
#define all(a) a.begin(),a.end()

#define Unique(x)                             (x).erase(unique(all(x)),(x).end())

#define     yes                                cout<<"YES"<<endl

#define     no                                 cout<<"NO"<<endl

#define     mem(a,i)                           memset(a, i, sizeof(a))

#define     Labib                              ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod   1000003                 
using namespace std;

class Dijkstra{
   public:
   int n,edge;
   int inf = INT_MAX;
   vector<vector<pair<int,int>>>adj;
   vector<int>dis;
   Dijkstra(int n){
    this->n=n;
    adj.resize(n+1);
    dis.assign(n+1,inf); 
   }
   void read_input(int edge)
   {
     int u,v,w;
     this->edge=edge;
     for(int i=0;i<edge;i++)
     {
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
     }
   }
   void dijkstra(int node)
   {
     dis[node]=0;
     priority_queue<pair<int,int>>pq;
     pq.push({0,node});
     while (!pq.empty())
     {
        pair<int,int>top = pq.top();
        pq.pop();
        int cost = -1*top.first,curr_node=top.second;
        for(auto child:adj[curr_node]){
            if(dis[child.first]>cost+child.second){
                dis[child.first]=cost+child.second;
                pq.push({-1*dis[child.first],child.first});
            }
        }
     }       
   }
   void print(int n)
   {
    this->n=n;
     for(int i=0;i<n;i++)
     {
        cout<<dis[i]<<" ";
     }
     cout<<endl;
   }
};


int main()
{
   Labib
    ll t=1;
    //ll_in1(t);
    while (t--)
    {
      
      int n,e;
      cin>>n>>e;
      Dijkstra ob(n);
      ob.read_input(e);
      ob.dijkstra(0);
      ob.print(n);
     
    
    } 

    return 0;
}
