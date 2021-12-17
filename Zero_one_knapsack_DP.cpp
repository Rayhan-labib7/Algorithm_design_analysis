#include<bits/stdc++.h>
#define ll                      long long int
#define endl                    '\n'
using namespace std;



void print_table(int item,int capacity,vector<vector<int>>table)
{

    for(int i=1;i<=item;i++)
   {
       for(int j=1;j<=capacity;j++)
       {
           cout<<table[i][j]<<" ";
       }
       cout<<endl;
   }
}
void print_taken_item(int item,int capacity,vector<vector<int>>table)
{
     vector<int>taken_item(item+1,0);

     int i=item;

     int j=capacity;

     while(i>0 && j>0)
     {
         if(table[i][j]!=table[i-1][j])
         {
             j-=table[i-1][j];
             taken_item[i]=1;
             i--;
         }
         else
         {
             i--;
         }
     }
     for(int i=1;i<taken_item.size();i++)
     {
         cout<<taken_item[i]<<" ";
     }
     cout<<endl;

}


int Knapsack(int item,int capacity,int weight[],int profit[])
{
    vector<vector<int>>table(item+1,vector<int>(capacity+1));

    for(int i=0;i<=item;i++)
    {
          table[i][0]=0;
    }
    for(int i=0;i<=capacity;i++)
    {
       table[0][i]=0;
    }
    for(int i=1;i<=item;i++)
    {

       for(int j=1;j<=capacity;j++)
       {
           if(weight[i-1]<=j)
           {
           table[i][j]=max(table[i-1][j],profit[i-1]+table[i-1][j-weight[i-1]]);
           }
           else
           {
               table[i][j]=table[i-1][j];
           }

       }

    }

    print_table(item,capacity,table);
    
    print_taken_item(item,capacity,table);
    
    return table[item][capacity];
}



int main()
{
   int weight[]={3,4,5,6};

   int profit[]={2,3,4,1};

   int item=sizeof(profit)/sizeof(profit[0]);

   int capacity=8;

   int maxi_profit=Knapsack(item,capacity,weight,profit);

   cout<<maxi_profit<<endl;
   
   return 0;
}


