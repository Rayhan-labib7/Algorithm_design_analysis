const ll MX=10000001;
ll phi[MX];
ll uniquePrime[MX];
void Sieve_ETF() //phi table and smallest divisor each element(prime factor)
{
    for (int i = 1; i < MX; i++)
    {
       phi[i] = i;
    }
    for (int i = 2; i < MX; i++)
     {
        if (phi[i] == i)
        {
            for (int j = i; j < MX; j += i) 
            {
                phi[j] -= phi[j] / i;
                if (!uniquePrime[j]) 
                {
                  uniquePrime[j] = i;
                }
            }
        }
    }
}
vector<ll>fun(ll n)  //calculate divisors each element efficent more than sqrt() 
{
   vector<ll>div;
   div.push_back(1);
   
   while (n>1)
   {
      ll d=uniquePrime[n];
      ll currPower=d;
      ll sz=div.size();
      while (n%d==0)
      {
        for(int i=0;i<sz;i++)
        {
          div.push_back(div[i]*currPower);
        }
        n/=d;currPower*=d;
      }
      
   }
   return div;
   
}
