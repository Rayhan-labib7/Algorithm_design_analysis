                                           

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

class Trie{
    struct node
    {
        node* next[2];
        int idx;
        node(){
            for(int i=0;i<2;i++){
                next[i]=NULL;
            }
        }
    };
    node* root=new node();
    public:
    Trie(){}
    void addValue(ll val,int idx)
    {
        node* head = root;
        for(int i=31;i>=0;i--){
            int x=(val&(1<<i));
            if(head->next[x]==NULL){
                head->next[x]=new node();
            }
            head=head->next[x];
            head->idx=idx;
        }
    }
    pair<ll,ll>query(ll a){
        node* head=root;
        ll ans=0,idx;
        for(int i=31;i>=0;i--){
            int x=1-((a>>i)&1);
            if(head->next[x]!=NULL){
                head=head->next[x];
                ans|=(1ll<<i);
            }
            else if(head->next[1-x]!=NULL){
                head=head->next[1-x];
            }
            else{
                break;
            }
            idx=head->idx;
        }
        return {ans,idx};
    }
    
};


int main()
{
   Labib
   ll n;
   cin>>n;
   ll val;
   Trie obj;
   for(int i=1;i<=n;i++){
    cin>>val;
    obj.addValue(val,i);
   }
   ll q;
   cin>>q;
   for(int i=1;i<=q;i++)
   {
    ll d;
    cin>>d;
    cout<<"Query "<<i<<": ";
    pair<ll,int>ret=obj.query(d);
    cout<<ret.second<<" "<<ret.first<<endl;
   }
   

    return 0;
}
