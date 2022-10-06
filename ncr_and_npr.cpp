class counting
{
    long long m;

public:
    vector<long long> fact, invfact;
    ll Mul(ll a,ll b)
    {
         return ((a%m)*(b%m))%m;
    }
    long long bigmod(long long n, long long p)
    {
        if (p == 0)
        {
            return 1ll;
        }
        ll ret = bigmod(n, p / 2);
        ret = Mul(ret, ret);
        if (p % 2 == 1)
        {
            ret = Mul(ret,n);
        }
        return ret;
    }
    counting(int n,long long m)
    {
        this->m=m;
        fact.resize(n+1);
        invfact.resize(n+1);
        fact[0]=1;
        for(long long i=1;i<=n;i++)
        {
           fact[i]=(fact[i-1]*i)%m;
        }
        invfact[n]=bigmod(fact[n],m-2);
        for(long long i=n;i>0;--i)
        {
            invfact[i-1]=(invfact[i]*i)%m;
        }
    }
    long long ncr(int n, int r)
    {
        if (r > n)
            return 0;
        return ((fact[n] * invfact[r]) % m * invfact[n - r]) % m;
    }
    long long npr(int n,int r)
    {
        if(r>n)
        return 0;
        return (fact[n]*invfact[n-r])%m;
    }
};
