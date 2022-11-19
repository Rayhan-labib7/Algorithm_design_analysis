                                           

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


class segment_tree
{
public:
    vector<ll>tree,arr,lazy;

    void build(int p,int begin,int end)
    {
        if(begin==end)
            {
                tree[p]=arr[begin];
                return;
            }
        int left=p<<1;
        int right=(p<<1)+1;
        int mid=(begin+end)>>1;
        build(left,begin,mid);
        build(right,mid+1,end);

    }
    void update_lazy(int p, int begin, int end)
    {
        tree[p] = lazy[p];

        if (begin != end)
            {
                int left=p<<1;
                int right=(p<<1)+1;
                lazy[left] = lazy[p];
                lazy[right] = lazy[p];
            }

        lazy[p] = 0;
    }
    void update(int p,int begin,int end,int l,int r,ll value)
    {
        if (lazy[p] != 0)
            update_lazy(p,begin,end);
        if(l>end | r<begin)
            return ;
        if(begin>=l && end<=r)
            {
                lazy[p] = value;
                update_lazy(p,begin,end);
                return;
            }
        int left=p<<1;
        int right=(p<<1)+1;
        int mid=(begin+end)>>1;
        update(left, begin, mid, l, r,value);
        update(right, mid+1, end, l, r,value);

    }
    void update1(int p,int begin,int end,int l,int r,ll value)
    {
        if (lazy[p] != 0)
            update_lazy(p,begin,end);
        if(l>end | r<begin)
            return ;
        if(begin>=l && end<=r)
            {
                
                tree[p]+=value;
                return;
            }
        int left=p<<1;
        int right=(p<<1)+1;
        int mid=(begin+end)>>1;
        update1(left, begin, mid, l, r,value);
        update1(right, mid+1, end, l, r,value);
    
    }

    ll query(int p,int begin,int end,int l,int r)
    {
        if (lazy[p] != 0)
            update_lazy(p,begin,end);
        if(l>end || r<begin)
            return 0;
        if (begin >= l && end <= r)
            return tree[p];
        int left=p<<1;
        int right=(p<<1)+1;
        int mid=(begin+end)>>1;
        ll a= query(left, begin,mid,l,r);
        ll b= query(right, mid+1,end,l,r);
        return a+b;

    }
    void print(int p, int begin, int end)
    {
        if (begin==end)
            return;
        int mid = (begin+end)>>1;
        print(p<<1, begin, mid);
        print((p<<1)+1, mid+1, end);
    }
    segment_tree(vector<ll> temp)
    {
        arr=temp;
        tree.resize(4*arr.size());
        build(1,0,arr.size()-1);
        lazy.assign(4*arr.size(),0ll);
    }
    ll rmq(int i,int j)
    {
        return query(1,0,arr.size()-1,i,j);
    }
    void update(int i,int j,ll value)
    {
        update(1,0,arr.size()-1,i,j,value);
    }
};

int main()
{
   Labib

    ll  n;

    cin>>n;

    vector<ll>v(n);

    for(int i=0;i<n;i++) cin>>v[i];

    segment_tree ob(v);

    ll q;

    cin>>q;

    while (q--)
    {
        ll type,l,r,val,idx;
        cin>>type;
        if(type==1)
        {
            cin>>idx;
            cout<<ob.rmq(idx-1,idx-1)<<endl;
            ob.update1(1,0,n-1,idx-1,idx-1,0);
        }
        else if(type==2)
        {
            cin>>idx>>val;
          
            ob.update1(1,0,n-1,idx-1,idx-1,val);
            
        }
        else{
            cin>>l;
            cout<<ob.rmq(l-1,l-1)<<endl;
        }
        
    }
    

    return 0;
}
