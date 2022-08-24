
#include<bits/stdc++.h> 
using namespace std; 
	

int lis( int arr[], int n ) 
{  

	vector<int>lis;
   lis.push_back(arr[0]);
	for (int i = 1; i < n; i++ ) 
	{ 
		
			if ( arr[i] > lis.back())
         {
            lis.push_back(arr[i]);
         } 
         else{
            int idx=lower_bound(lis.begin(),lis.end(),arr[i]) - lis.begin();
            lis[idx]=arr[i];
         }
				

	} 

	
	return lis.size();
} 
	
/* Driver program to test above function */
int main() 
{ 
	int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 }; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	printf("Length of lis is %d\n", lis( arr, n ) ); 
	return 0; 
}
