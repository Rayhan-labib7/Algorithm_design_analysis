#include<bits/stdc++.h>
using namespace std;
void heapify(vector<int>&v,int n,int i)
{
    int leargest=i,left,right;
    left=i*2+1;
    right=i*2+2;
    if(left<n && v[left]>v[leargest])
    {
        leargest=left;
    }
    if(right<n && v[right]>v[leargest])
    {
        leargest=right;
    }
    if(leargest!=i)
    {
        swap(v[leargest],v[i]);
        heapify(v,n,leargest);
    }
}
void heapsort(vector<int>&v,int n)
{
    for(int i=(n/2)-1;i>=0;i--)
    {
       heapify(v,n,i);
    }
    for(int i=n-1;i>=0;i--)
    {
        swap(v[0],v[i]);
        heapify(v,i,0);
    }
}
int main()
{
    vector<int>v={14,3,7,1,8,5,4};
    int n=v.size();
    heapsort(v,n);
    for(auto it : v)
    {
        cout<<it<<" ";
    }
    cout<<endl;
}
