#include<bits/stdc++.h>
using namespace std;
void merge(vector<int>&v,int left,int mid,int right)
{
     int n1=mid-left+1;
     int n2=right-mid;
     int L[n1+1],R[n2+1];
     for(int i=1;i<=n1;i++)
     {
         L[i]=v[left+i-1];
     }
     for(int i=1;i<=n2;i++)
     {
         R[i]=v[mid+i];
     }
     L[n1+1]=INT_MAX;
     R[n2+1]=INT_MAX;
     int i=1,j=1;
     for(int k=left;k<=right;k++)
     {
         if(L[i]<=R[j])
         {
             v[k]=L[i];
             i++;
         }
         else
         {
             v[k]=R[j];
             j++;
         }
     }
}
void merge_sort(vector<int>&v,int left,int right)
{
    if(left<right)
    {
        int mid=(left+right)/2;
        merge_sort(v,left,mid);
        merge_sort(v,mid+1,right);
        merge(v,left,mid,right);
    }
}
int main()
{
    vector<int>v{10,5,6,18,6,2,9,4};
    int n=v.size();
    merge_sort(v,0,n-1);
    for(auto it : v)
    {
        cout<<it<<" ";
    }
}
