class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // int maxEleIndex=max_element(nums.begin(),nums.end())-nums.begin();
        int n=nums.size();
        vector<int> ans(n,-1);
        stack<int> st;
        for(int i=n-1;i>=0;i--)
        {
            st.push(nums[i]);
        }
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty()&&st.top()<=nums[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                ans[i]=st.top();
            }
            st.push(nums[i]);
        }
        // for(int i=n-1;i>maxEleIndex;i--)
        // {
        //     while(!st.empty()&&st.top()<=nums[i])
        //     {
        //         st.pop();
        //     }
        //     if(!st.empty())
        //     {
        //         ans[i]=st.top();
        //     }
        //     st.push(nums[i]);
        // }
        return ans;
    }
};