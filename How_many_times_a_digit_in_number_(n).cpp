int findTrailingZeros2(int n,int x){
    int cnt=0;
    while(n%x==0){
        cnt++;
        n/=x;
    }
    return cnt;
}
