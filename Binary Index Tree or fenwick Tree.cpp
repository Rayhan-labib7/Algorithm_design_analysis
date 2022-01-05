
                                                                  /*--------------------|
                                                                  |بِسْمِ الّٰلهِ الرَّحْمٰنِ الرَحِيْمِ |
                                                                  |____________________*/

                                                       /*--------------->Logic%2==0---------------->*/


                                                                      //আগে যদি জানতাম
                                                                      //      CSE
                                                                     // তে কি আসতাম 😢*

#include<bits/stdc++.h>
#define CASE(t)                 printf("Case %d: ",t)
#define gcd(a,b)                __gcd(a,b)
#define lcm(a,b)                ((a)*(b))/gcd(a,b)
#define PI                      2*acos(0.0)
#define ll                      long long int
#define pq_small              priority_queue < int, vector <int>, greater <int> > pq;
#define endl                    '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int a[10000];
int tree[10000];
int Read(int idx)
{
    int sum=0;
    while(idx>0)
    {
        sum+=tree[idx];
        idx-=(idx & -idx);
    }
    return sum;
}
void update(int idx,int val,int n)
{
    while(idx<=n)
    {
        tree[idx]+=val;
        idx+=(idx & -idx);
    }
}
void print(int *tree,int n)
{
    for(int i=1;i<=n;i++)
    {
        cout<<tree[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    
    optimize();
    //cout<<fixed<<setprecision(12);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
       cin>>a[i];
       update(i,a[i],n);
    }
    print(tree,n);
    int x;
    cin>>x;
    int ans=Read(x);
    cout<<ans<<endl;




/*---------->HaPpY CoDiNg----------->*/
return 0;
}
/* 
16
1 0 2 1 1 3 0 4 2 5 2 2 3 1 0 2
10
ans=19
*/
