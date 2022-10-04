ll Mul(ll a,ll b,ll Mod)
{
   return ((a%Mod)*(b%Mod))%Mod;
}
ll bigMod(ll n,ll r,ll Mod)
{
    if(r==0) 
    {
      return 1ll;
    }
    ll ret=bigMod(n,r/2,Mod);
    ret=Mul(ret,ret,Mod);
    if(r%2==1)
    {
      ret=Mul(ret,n,Mod);
    }
    return ret;
}



int main()
{
    int x,y;
    cout<<bigMod(4,5,7)<<endl;
  

    return 0;
}
