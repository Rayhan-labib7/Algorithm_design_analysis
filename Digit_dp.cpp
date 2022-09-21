                                           

#include <bits/stdc++.h>

#define     ll                                 unsigned long long    

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

ll dp[10][100][2];
ll prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,97};
bool check(int sum)
{
    for(auto u:prime)
    {
        if(u==sum)
        {
            return 1;
        } 
    }
    return 0;
}
ll digit_dp(string s,int pos,int sum,int isSmall)
{
       if(pos==s.size())
       {
            if(check(sum))
            {
                return 1;
            }
            else{
                return 0;
            }
       }
       if(dp[pos][sum][isSmall]!=-1)
       {
        return dp[pos][sum][isSmall];
       }
       ll lo=0,hi=s[pos]-'0',res=0;
       if(isSmall)
       {
        hi=9;
       }
        for(int i=lo;i<=hi;i++)
        {
            ll newIsSmall=isSmall | (i<hi);
            ll val=digit_dp(s,pos+1,sum+i,newIsSmall);
            res=res+val;
        }
        
        return dp[pos][sum][isSmall]=res;
       
}

int main()
{
   Labib
    ll t;
    ll_in1(t);
    while (t--)
    {
        ll l,r;

        ll_in2(l,r);

        l=l-1;

        string a=to_string(l);

        string b=to_string(r);

        memset(dp,-1,sizeof(dp));

        ll ans1=digit_dp(a,0,0,0);

        memset(dp,-1,sizeof(dp));

        ll ans2=digit_dp(b,0,0,0);

        cout<<ans2-ans1<<endl;
    
    } 

    return 0;
}
