#define mx5   200005
int phi[mx5];
void phitable()
{
    phi[1]=1;
    for(int i=2;i<mx5;i++)
    {
        if(phi[i]==0)
        {
            phi[i]=i-1;
            for(int j=i+i;j<mx5;j+=i)
            {
                if(phi[j]==0)phi[j]=j;
                phi[j]=phi[j]-phi[j]/i;
            }
        }
    }


}
