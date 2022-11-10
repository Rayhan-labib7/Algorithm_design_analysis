int findTrailingZeros(int n,int x){   // n=number and x=how many times digit contain the number(n)
    int cnt=0;
    while(n>0){
        cnt+=(n/x);
        n/=x;
    }
    return cnt;
}
