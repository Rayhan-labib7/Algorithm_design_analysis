///-----------------------------------Sieve of Eratosthenes----------------------->>>>
ll prime_size=1e7+1;
vector<ll>primes;
vector<bool> mark(prime_size+4);
void sieve(){
    ll i,j;
    mark[0]=mark[1]=1;
    for(i=4; i<prime_size; i+=2)mark[i]=1;
    for(i=3; i*i<=prime_size; i+=2){
        if(!mark[i]){
            for(j=i*i; j<=prime_size; j+=i*2)mark[j]=1;
        }
    }
    primes.push_back(2);
    for(i=3; i<=prime_size; i+=2)if(!mark[i])primes.push_back(i);
}
///------------------>smaller prime factor ------------>>>>>>>>>
const int N = 202222;
vector<int>pf(N);

void smallestpf()
{
    for(int i=2; i<N; i+=2)
        pf[i]=2,pf[i-1]=i-1;
    for(int i=3; i*i<N; i+=2)
        if(pf[i]==i)
            for(int j=i*i; j<N; j+=2*i)
                if(pf[j]==j)
                    pf[j]=i;
}
///---------------------------------------------factorize----------------------------->>
const int N = 202222;
vector<vector<int>>fact(N);
void factorize(){
	for(int i=1; i*i<N; i++){
		for(int j=i; j*i<N; j++){
			fact[i*j].push_back(i);
			if(i!=j)
            {
                fact[i*j].push_back(j);
            }
		}
	}
}

//Another sieve
void sieve(vector<int> &v)
{
    int b,i,j;
   int a=7866556;
    bool N[a];
    for(i=0;i<a;i++)
    {
        N[i]=1;
    }
    for(i=0;i<a;i++)
    {
        if(N[i]==0)
        {
            continue;
        }
        else
        {
            v.push_back(i+2);
            for(j=i*2+2;j<=a;j+=(2+i))
            {
                N[j]=0;
            }
        }
    }
}


///------------------------------------factorial digit count--------------------------->>>>

int findDigits(ll n)
{

    if (n < 0)
        return 0;

    if (n <= 1)
        return 1;

    double digits = 0;

    for (int i=2; i<=n; i++)
    {
        digits += log10(i);
    }

    return floor(digits) + 1;
}

///------------------------Modeuolo (lon(n)) complexity------->>>>>>

ll solve(ll base,ll pw)
{
    ll l=base,ans=1;
    while(pw)
    {
        if(pw%2==1)
        {
            ans=ans*l;
        }
        l=l*l;
        pw/=2;
    }
    return ans;
}

///---------------------------geometric progration using PRIME FACTORIZATION moduler atritmetic--->>


ll mod=1000000007;
ll inverse(ll k)
{
    ll Sum=1,pw=mod-2;
    while(pw>0)
    {
        if(pw%2==1)
        {
            Sum=(Sum*k)%mod;
        }
        k=(k*k)%mod;
        pw/=2;
    }
    return Sum;
}
ll value(ll base,ll pw) ///base==prime vlaue and pw=power
{
    ll sum=1,b=base,res;///base=2,pw=6.....so=2^1+2^2+2^3+2^4+2^5+2^6;
    while(pw>0)
    {
        if(pw%2==1)
        {
            sum=(sum*base)%mod;
        }
        base=(base*base)%mod;
        pw/=2;
    }
    sum=sum-1;
    sum=(sum*b)%mod;
    res=(sum*inverse(b-1))%mod;
    return res;
}

///--------------------------1 to n number SOD------------>>
#define SIZE 1000005
long long  SOD[SIZE];
void NOD_SOD(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j+=i)
        {
            SOD[j] += i;
        }
    }
}

///-----------How to determine the level of each node in the given tree?------>
 vector <int> v[10] ;   //Vector for maintaining adjacency list explained above
    int level[10]; //To determine the level of each node
    bool vis[10]; //Mark the node if visited
    void bfs(int s) {
        queue <int> q;
        q.push(s);
        level[ s ] = 0 ;  //Setting the level of the source node as 0
        vis[ s ] = true;
        while(!q.empty())
        {
            int p = q.front();
            q.pop();
            for(int i = 0;i < v[ p ].size() ; i++)
            {
                if(vis[ v[ p ][ i ] ] == false)
                {
            //Setting the level of each node with an increment in the level of parent node
                    level[ v[ p ][ i ] ] = level[ p ]+1;
                     q.push(v[ p ][ i ]);
                     vis[ v[ p ][ i ] ] = true;
      }
            }
        }
    }

    ///-----Longest subsequence of stiring without repeated char. using two pointer or sliding window-------------->


    void longest_sunsequcnce_distinct_char(string s)
{
      ll sz=s.size();
      ll i=0,j=0;
      vector<int>v(400,0);
      v[s[0]]++;
      ll res=1;
      while(j!=sz-1)
      {
          if(v[s[j+1]]==0)
          {
              j++;
              v[s[j]]=1;
              res=max(res,j-i+1);
          }
          else
          {
              v[s[i]]--;
              i++;
          }
      }

      cout<<res<<endl;

}
 primes in range       1 - n

1 - 100(1e2) -> 25 pimes
1 - 1000(1e3) -> 168 primes
1 - 10000(1e4) -> 1229 primes
1 - 100000(1e5) -> 9592 primes
1 - 1000000(1e6) -> 78498 primes
1 - 10000000(1e7) -> 664579 primes
large primes ->
104729 1299709 15485863 179424673 2147483647 32416190071 112272535095293 48112959837082048697

const int fx[]={+1,-1,+0,+0};
const int fy[]={+0,+0,+1,-1};
const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move

--------------Z Algo----------->


ll *Z_algo(string s,ll n)
{
    ll *z=new ll[n];

    ll l=0,r=0;

    z[0]=0;

    for(ll i=1;i<n;i++)
    {
        if(i>r)
        {
            l=i;

            r=i;

            while(r<n && s[r-l]==s[r])
            {
                r++;
            }

            r--;

            z[i]=r-l+1;
        }
        else
        {
            ll j=i-l;

            if(z[j]<r-i+1)
            {
                z[i]=z[j];
            }
            else
            {
                l=i;

                while(r<n && s[r-l]==s[r])
                {
                    r++;
                }

                r--;

                z[i]=r-l+1;
            }
        }
    }
    return z;
}

    ----main function call---->

    string s;

    cin>>s;

    ll n=s.size();

    ll *z=Z_algo(s,n);

    ------------------------------------------end----------------------

  //  Euler Product formula--------------------->>
 int Phi(int n)
{
	int cnt=n;
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			while(n%i==0)
			{
                            n/=i;
			}
				cnt-=(cnt/i);  
			
		}
	}
	if(n>1) //if n is greatter than squre of i*i
	{
	   cnt-=(cnt/n);
	}
	return cnt;
}
---------------------------------end------------------->>

------------>>modular----------->
int mod_value(int base,int power,int mod)
{
	int result=1;            //initial result
	base=base%mod;           //update base if base is more than or equal mod// if isn't calculation for this reason some value given negative
	if(base==0) return 0;    // mod value return always zero 
	while(power>0)
	{
		if(power&1)
		{
			result=(result*base)%mod;
		}
		power=power>>1; // y/2
		base=(base*base)%mod;
	}  
	return result;
}

-----------end--------------------------

------------- A Dynamic Programming based solution to compute nCr % p
#include <bits/stdc++.h>
using namespace std;
 
// Returns nCr % p
int nCrModp(int n, int r, int p)
{
    // Optimization for the cases when r is large
    if (r > n - r)
        r = n - r;
 
    // The array C is going to store last row of
    // pascal triangle at the end. And last entry
    // of last row is nCr
    int C[r + 1];
    memset(C, 0, sizeof(C));
 
    C[0] = 1; // Top row of Pascal Triangle
 
    // One by constructs remaining rows of Pascal
    // Triangle from top to bottom
    for (int i = 1; i <= n; i++) {
 
        // Fill entries of current row using previous
        // row values
        for (int j = min(i, r); j > 0; j--)
 
            // nCj = (n-1)Cj + (n-1)C(j-1);
            C[j] = (C[j] + C[j - 1]) % p;
    }
    return C[r];
}
int main()
{
    int n = 10, r = 2, p = 13;
    cout << "Value of nCr % p is " << nCrModp(n, r, p);
    return 0;
}
--------------->>>end---------------->>>

----big number multiply------------>
string multiple(string s1,string s2)
{
    ll s1_len=s1.size();
    ll s2_len=s2.size();
    vector<int>result(s1_len+s2_len,0);
    ll carry=0,sum=0,n1=0,n2=0,dig1,dig2;
    for(int i=s1_len-1;i>=0;i--)
    {
        carry=0;n2=0;dig1=s1[i]-'0';
        for(int j=s2_len-1;j>=0;j--)
        {
            dig2=s2[j]-'0';
            sum=dig1*dig2+result[n1+n2]+carry;
            carry=sum/10;
            result[n1+n2]=sum%10;
            n2++;
        }
        if(carry>0)
        {
            result[n1+n2]+=carry;
        }
        n1++;
    }
    ll i=result.size()-1;
    while(i>=0 && result[i]==0) i--;
    if(i==-1) return "0";
    string s;
    while(i>=0)
    {
       s+=to_string(result[i--]);
    }
    return s;
}
-------------------end---------->>>
------------fenwick tree--------->>>
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
--------------------------->>end--------------->>
----------ncr dynamic programming------------>
ll nCr(ll n, ll r)
{
    if(n<r)return 0;
    if((n-r)<r) r=n-r;
    ll dp[r+1];
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=min(r,i);j>0;j--)
        {
            dp[j]=(dp[j]+dp[j-1]);
        }
    }
    return dp[r];
}
and ncr formula=(n*(n-1)*(n-2)*(n-3))/24;
