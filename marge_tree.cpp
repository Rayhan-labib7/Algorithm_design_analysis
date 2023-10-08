void build(int node,int begin,int end)
    {
        if(begin==end)
            {
                tree[node].push_back(arr[begin]);
                return;
            }
        int left=node<<1;
        int right=(node<<1)+1;
        int mid=(begin+end)>>1;
        build(left,begin,mid);
        build(right,mid+1,end);
        ll i=0,j=0;
        while (i<tree[left].size() and j<tree[right].size())
		{
			if(tree[left][i]<=tree[right][j]){
				tree[node].push_back(tree[left][i]);
				i++;
			}
			else{
				tree[node].push_back(tree[right][j]);
				j++;
			}
		}
		while (i<tree[left].size())
		{
			tree[node].push_back(tree[left][i]);
			i++;
		}
		while (j<tree[right].size())
		{
			tree[node].push_back(tree[right][j]);
			j++;
		}

    }
