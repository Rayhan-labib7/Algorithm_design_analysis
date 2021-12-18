
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
using namespace std;

int FIND_MAXIMUM_Crossing_SUB_ARRY(int arry[],int low,int mid,int high)
{
    int left_sum=-1,sum=0;
    for(int i=mid;i>=low;i--)
    {
        sum+=arry[i];
        if(sum>left_sum)
        {
            left_sum=sum;
        }
    }
    int right_sum=-1;
    sum=0;
    for(int i=mid+1;i<high;i++)
    {
        sum+=arry[i];
        if(sum>right_sum)
        {
            right_sum=sum;
        }
    }
    return max(max(left_sum,right_sum),left_sum+right_sum);
}


int FIND_MAXIMUM_SUB_ARRY(int arry[],int low,int high)
{
    if(low==high)
    {
        return arry[low];
    }
    int mid=(low+high)/2;
    return max(max(FIND_MAXIMUM_SUB_ARRY(arry,low,mid),FIND_MAXIMUM_SUB_ARRY(arry,mid+1,high)),FIND_MAXIMUM_Crossing_SUB_ARRY(arry,low,mid,high));
}
int main()
{
    int arry[]={-2,2,-8,3,-2,2,1,-4,3};

    int Size=sizeof(arry)/sizeof(arry[0]);

    int ansr=FIND_MAXIMUM_SUB_ARRY(arry,0,Size-1);

    cout<<ansr<<endl;


/*---------->HaPpY CoDiNg----------->*/
return 0;
}

