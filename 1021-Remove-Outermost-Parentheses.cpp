class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int balance = 0,n= s.size();
        for(int i = 0;i < n;i++){
            if(s[i] == ')')balance--;
            if(balance > 0)ans.push_back(s[i]);
            if(s[i] == '(')balance++;
        }
        return ans;
    }
};