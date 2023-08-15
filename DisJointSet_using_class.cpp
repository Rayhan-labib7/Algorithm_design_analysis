class DisJointSet
{
    public:
    int n;
    vector<int>sz,parent;
    DisJointSet(int _n)
    {
        n=_n;
        sz.resize(n+1,1);
        parent.resize(n+1);
        for(int i=1;i<=n;i++)
        {
            parent[i]=i;
        }
    }
    
    int find(int x)
    {
        if(parent[x]==x)
        {
           return parent[x];
        }
        return parent[x]=find(parent[x]);
    }

    void union_op(int x,int y)
    {
        int xRoot = find(x), yRoot = find(y);
        if(xRoot == yRoot)
        {
            return;
        }
        if(sz[xRoot]<sz[yRoot])
        {
            parent[xRoot]=yRoot;
            sz[yRoot]+=sz[xRoot];
        }
        else 
        {
            parent[yRoot]=xRoot;
            sz[xRoot]+=sz[yRoot];
        }
    }
};
