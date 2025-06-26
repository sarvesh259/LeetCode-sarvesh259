class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        stack<int> st;
        int ans=0;
        for(int i=0;i<h.size();i++)
        {
            while(!st.empty()&&h[st.top()]>h[i])
            {
                int el=h[st.top()];
                st.pop();
                int pse=(st.empty()?-1:st.top());
                ans=max(ans,(el*(i-pse-1)));
            }
            st.push(i);
        }
         while(!st.empty())
            {
                int el=h[st.top()];
                st.pop();
                int pse=(st.empty()?-1:st.top());
                int nse=h.size();
                ans=max(ans,(el*(nse-pse-1)));
            }
            return ans;
    }
};