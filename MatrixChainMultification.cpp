#include<bits/stdc++.h>
using namespace std ;
const int N=6;
int cost[N][N];
void matrixchinmul(vector<int>&v)
{
    int n=v.size();
    for(int len=2;len<=n;len++)
    {
        for(int i=1;i<=n-len;i++)
        {
            int j=i+len-1;
            cost[i][j]=INT_MAX;
            for(int k=i;k<j;k++)
            {
                cost[i][j]=min(cost[i][j],cost[i][k]+cost[k+1][j]+v[i-1]*v[k]*v[j]);
            }
        }
    }
}
int main()
{
    //Labib
    vector<int>v{4,10,3,12,20,7};
    matrixchinmul(v);
    cout<<"Table Print :"<<endl;
    for(int i=1;i<v.size();i++)
    {
        for(int j=1;j<v.size();j++)
        {
            cout<<cost[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Total Cost : "<<cost[1][v.size()-1];
}
