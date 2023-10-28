                                           

#include <bits/stdc++.h>

#define     ll                                 long long int   

#define     ll_in1(a)                          cin>>a

#define     ll_in2(a,b)                        cin>>a>>b

#define     ll_in3(a,b,c)                      cin>>a>>b>>c

#define     take_vector_int(x,o,n)             for(int i=o;i<=n;i++){cin>>x[i];}    

#define     srt(v)                             sort(v.begin(),v.end());

#define     rsrt(v)                            reverse(v.begin(),v.end())

#define     gcd(a, b)                          __gcd(a, b)

#define     vi                                 vector<int>

#define     vll                                vector<ll>

#define     endl                               '\n'

const int dx[] = {+1,-1,+0,+0}; ///Rock's Move

const int dy[] = {+0,+0,+1,-1}; ///Rock's Move


const       ll                                 INF = 1122334455667788990;
#define all(a) a.begin(),a.end()

#define Unique(x)                             (x).erase(unique(all(x)),(x).end())

#define     yes                                cout<<"YES"<<endl

#define     no                                 cout<<"NO"<<endl

#define     mem(a,i)                           memset(a, i, sizeof(a))

#define     Labib                              ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod   1000003                 
using namespace std;

vector<vector<string>>v;
void Strem_word(string s)
{
    stringstream sentence(s);
    string word;
    vector<string>temp;
    ll cnt=0;
    while (sentence>>word)
    {
      temp.push_back(word);
    }
    v.push_back(temp);
}

bool compair(vector<string>&a,vector<string>&b)
{
   set<char>diff_a(a[2].begin(),a[2].end()),diff_b(b[2].begin(),b[2].end());
   ll len_a=a[2].size()*diff_a.size();
   ll len_b=b[2].size()*diff_b.size();
   if(a.size()==b.size() && a[2]==b[2] && len_a==len_b && a[1]==b[1])
   {
     return a[0]>b[0];
   }
   if(a.size()==b.size() && a[2]==b[2] && len_a==len_b)
   {
     return stoi(a[1])>stoi(b[1]);
   }
   if(a.size()==b.size() && len_a==len_b){
     return a[2]>b[2];
   }
   if(a.size()==b.size()){
    return a[2]>b[2];
   }
   return a.size()>b.size();
}

int main()
{
   Labib    
   string s;
   while(getline(cin,s))
   {
     Strem_word(s); 
   }
   sort(v.begin(),v.end(),compair);
   for(auto u:v){
    cout<<u[0]<<" "<<u[1]<<endl;
   }
    return 0;
}
