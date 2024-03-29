class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
      int   n=heights.size();
         stack<int> st;
        vector<int> left(n);
        for (int i = 0; i < n; i++)
        {
            if (st.empty())
            {
                left[i] = 0;
                st.push(i);
            }
            else
            {
                while (!st.empty() && heights[st.top()] >= heights[i])
                {
                    st.pop();
                }
                left[i] = st.empty() ? 0 : st.top() + 1;
                st.push(i);
            }
        }
        while (!st.empty())
        {
            st.pop();
        }
        
        vector<int>right(n);
        for(int i=n-1;i>=0;i--)
        {
            if(st.empty())
            {
                right[i]=n-1;
                st.push(i);
            }
            else
            {
                while (!st.empty() && heights[st.top()]>=heights[i])
                {
                    st.pop();
                }
                right[i]=st.empty()?n-1:st.top()-1;
                st.push(i);
                
            }
        }
        int mx=INT_MIN;
       
        for(int i=0;i<n;i++)
        {
            int x=right[i]-left[i]+1;
            mx=max(mx,x*heights[i]);
        }
        return mx;
        
    }
};
