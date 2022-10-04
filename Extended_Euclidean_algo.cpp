int Gcd(int a,int b,int& x,int& y)
{
  if(b==0)
  {
    x=1;
    y=0;
    return a;
  }
  int x1,y1;
  int d=Gcd(b,a%b,x1,y1);
  x=y1;
  y=x1-y1*(a/b);
  return d;
}


int main()
{
    int x,y;
    cout<<Gcd(4,7,x,y)<<endl;
    cout<<x<<endl;

    return 0;
}
