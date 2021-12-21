#include<bits/stdc++.h>
using namespace std;
void print_cut_point(vector<vector<int>>&table,int n)
{
    int i=n-1,j=n;
    vector<int>cut;
    while(i>0 && j>0)
    {
        if(table[i][j]!=table[i-1][j])
        {
            cut.push_back(i);
            j-=i;
        }
        else
        {
            i--;
        }

    }
    for(auto u : cut)
    {
        cout<<u<<" ";
    }
    cout<<endl;
}
void print_table(vector<vector<int>>&table,vector<int>&v,int n)
{
    int i,j;
    for( i=0;i<n;i++)
    {
        for( j=0;j<=n;j++)
        {
            if(i==0 || j==0)
            {
                table[i][j]=0;
            }
            else
            {
                if(j>=i)
                {
                    table[i][j]=max(table[i-1][j],v[i-1]+table[i][j-i]);
                }
                else
                {
                    table[i][j]=table[i-1][j];
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(j=0;j<=n;j++)
        {
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Maximum_profit :"<<table[n-1][n]<<endl;
    print_cut_point(table,n);
}
void cutrod(vector<int>&v,int n)
{
    vector<vector<int>>table(n+1,vector<int>(n));

    print_table(table,v,n);
}
int main()
{
    vector<int>v{2,5,9,6,7};
    int n=v.size();
    cutrod(v,n);
}
