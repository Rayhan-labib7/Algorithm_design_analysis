
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
void print_table(vector<vector<int>>table,int len1,int len2)
{
    for(int i=0;i<=len1;i++)
    {
        for(int j=0;j<=len2;j++)
        {
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }
}
void long_sequence(vector<vector<int>>table,char *s1,char *s2,int len1,int len2)
{
    int i=len1;
    int j=len2;
    vector<char>s;
    while(i>0 && j>0)
    {
        if(s1[i-1]==s2[j-1])
        {
            s.push_back(s1[i-1]);
            i--;
            j--;
        }
        else if(table[i-1][j]>table[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    for(int i=s.size()-1;i>=0;i--)
    {
        cout<<s[i];
    }
    cout<<endl;
}
void lcsAlgo(char *s1,char *s2,int len1,int len2)
{
    vector<vector<int>>table(len1+1,vector<int>(len2+1));

    for(int i=0;i<=len1;i++)
    {
        for(int j=0;j<=len2;j++)
        {
            if(i==0 || j==0)
            {
               table[i][j]=0;
            }
            else if(s1[i-1]==s2[j-1])
            {
                table[i][j]=table[i-1][j-1]+1;
            }
            else
            {
                table[i][j]=max(table[i-1][j],table[i][j-1]);
            }
        }
    }
    print_table(table,len1,len2);
    long_sequence(table,s1,s2,len1,len2);
    cout<<table[len1][len2]<<endl;
}

int main()
{
    char s1[]="STONE";
    char s2[]="LONGEST";
    int len1=strlen(s1);
    int len2=strlen(s2);
    lcsAlgo(s1,s2,len1,len2);



/*---------->HaPpY CoDiNg----------->*/
return 0;
}

