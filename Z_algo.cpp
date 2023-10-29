auto z_algo(string s)
{
    ll len = s.size();
    ll l=0,r=0;
    vector<ll>z(len);
    for(int i=1;i<len;i++)
    {
        if(i>r)
        {
            l=r=i;
            while (r<len and s[r]==s[r-l])
            {
                r++;
            }
            z[i]=r-l;
            r--;
        }
        else{
            ll idx=i-l;
            if(i+z[idx]<=r)
            {
                z[i]=z[idx];
            }
            else
            {
                l=i;
                while (r<len and s[r]==s[r-l])
                {
                    r++;
                }
                z[i]=r-l;
                r--;
            }
        }
    }
    return z;
}
