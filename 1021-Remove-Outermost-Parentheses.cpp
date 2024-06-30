class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        stack<char> st;
        int n = s.size();
        for(int i = 0;i < n;i++){
            if(s[i] == ')')st.pop();
            if(!st.empty())ans.push_back(s[i]);
            if(s[i] == '(')st.push(s[i]);
        }
        return ans;
    }
};