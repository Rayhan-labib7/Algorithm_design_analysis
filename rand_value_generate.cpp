#include<bits/stdc++.h>
#include<time.h>
using namespace std;
int main()
{
    srand(time(0));
    vector<int>v;
    cout<<"50 randoms number (50-100):"<<endl;
    for(int i=0;i<50;i++)
    {
        int temp=rand()%101;
        if(temp<50)temp+=50;
        v.push_back(temp);
    }
    for(auto u : v)
    {
        cout<<u<<" ";
    }
}
