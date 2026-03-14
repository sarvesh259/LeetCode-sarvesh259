class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+") {
                int t1 = st.top();
                st.pop();
                int t2 = st.top();
                st.pop();
                st.push(t1 + t2);

            } else if (tokens[i] == "-") {
                int t1 = st.top();
                st.pop();
                int t2 = st.top();
                st.pop();
                st.push(t2 - t1);
            } else if (tokens[i] == "*") {
                int t1 = st.top();
                st.pop();
                int t2 = st.top();
                st.pop();
                st.push(t1 * t2);
            } else if (tokens[i] == "/") {
                int t1 = st.top();
                st.pop();
                int t2 = st.top();
                st.pop();
                st.push(t2 / t1);
            } else {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};