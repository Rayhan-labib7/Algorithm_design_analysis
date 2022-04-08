#include<bits/stdc++.h>
#define ll   long long int 
using namespace std;
const ll m = 6469693231;
const ll b = 347;
int main()
{
    string s;
    cin>>s;
    ll n=s.size();
    vector<ll>hsh(n);
    ll h=0;
    //hash value store
    for(int i=0;i<n;i++)
    {
        h=(h*b+s[i]-'A'+1)%m;
        hsh[i]=h;
    }
    ll power[n+1];
    power[0]=1;
    //power calculate
    for(int i=1;i<=n;i++)
    {
        power[i]=(power[i-1]*b)%m;
    }
    int l1,r1,l2,r2;
    cin>>l1>>r1>>l2>>r2;
    ll mx=hsh[r1];
    ll mn=(l1==0)?0ll:(hsh[l1-1]*power[r1-l1+1]);
    ll first=((mx-mn)%m+m)%m;
    mx=hsh[r2];
    mn=(l2==0)?0ll:(hsh[l2-1]*power[r2-l2+1]);
    ll second=((mx-mn)%m+m)%m;
    if(first==second)
    {
        cout<<"matchig"<<endl;
    }
    else
    {
        cout<<"not matching"<<endl;
    }
}
