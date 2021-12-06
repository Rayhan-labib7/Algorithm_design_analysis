
                                                                  /*--------------------|
                                                                  |بِسْمِ الّٰلهِ الرَّحْمٰنِ الرَحِيْمِ |
                                                                  |____________________*/

                                                       /*--------------->Logic%2==0---------------->*/


                                                                      //আগে যদি জানতাম
                                                                      //      CSE
                                                                     // তে কি আসতাম 😢*

#include<bits/stdc++.h>
#define ll                      long long int
#define endl                    '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int Find_maximum_sub_arry(int a[],int low,int high)
{
    int n=high+1;
    int mid;
    if(low==high)
    {
        return (a[low],low,high);
    }
    else
    {
        mid=(low+high)/2;
    }
    int left_mss=Find_maximum_sub_arry(a,low,mid);
    int right_mss=Find_maximum_sub_arry(a,mid+1,high);
    int sum=0,right_sum=INT_MIN,left_sum=INT_MIN;
    for(int i=mid;i<n;i++)
    {
        sum+=a[i];
        right_sum=max(right_sum,sum);
    }
    sum=0;
    for(int i=(mid-1);i>=0;i--)
    {
        sum+=a[i];
        left_sum=max(left_sum,sum);
    }
    int maxx=max(left_sum,right_sum);
    return max(maxx,left_sum+right_sum);
}



int main()
{

   int a[]={3,-2,5,-1};
   int siz = sizeof(a) / sizeof(a[0]);
   int ans=Find_maximum_sub_arry(a,0,siz-1);
   cout<<ans<<endl;

/*---------->HaPpY CoDiNg----------->*/
return 0;
}

