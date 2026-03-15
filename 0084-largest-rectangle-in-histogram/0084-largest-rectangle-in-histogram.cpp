class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int ans = 0;
        stack<int> st;
        for (int i = 0; i < h.size(); i++) {
            while (!st.empty() && h[st.top()] > h[i]) {
                int temp = st.top();
                st.pop();
                int prev = -1;
                if (!st.empty()) {
                    prev = st.top();
                }
                ans = max((i - prev - 1) * h[temp], ans);
            }
            st.push(i);
        }
        while (!st.empty()) {
            int temp = st.top();
            st.pop();
            int prev = -1;
            if (!st.empty()) {
                prev = st.top();
            }
            int curh = (h.size() - prev - 1);
            ans = max(ans, curh * h[temp]);
        }
        return ans;
    }
};