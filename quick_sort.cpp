#include<bits/stdc++.h>
using namespace std;
int partition(vector<int>&v,int low,int high)
{

    int pivot=v[low];
    int i=low,j=high;
    while(i<j)
    {
        while(v[i]<=pivot)
        {
            i++;
        }
        while(v[j]>pivot)
        {
            j--;
        }
        if(i<j){
        swap(v[i],v[j]);
        } 
    }
    swap(v[low],v[j]);
    return j;
    
}
void quickSort(vector<int>&v,int low,int high)
{   
    if(low<high)
    {
       int pi=partition(v,low,high);
       quickSort(v,low,pi-1);
       quickSort(v,pi+1,high);
    }
    
}
int main()
{
    //Labib
    vector<int>v{10,5,7,15,2,1,4};
    int n=v.size();
    quickSort(v,0,n-1);
    for(auto it : v)
    {
        cout<<it<<" ";
    }
}
