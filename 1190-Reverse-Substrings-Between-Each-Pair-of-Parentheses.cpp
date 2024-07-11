class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        string temp = "";
        string ans = "";
        int i = 0,n = s.size(),tsz;
        while(i < n){
            if(s[i] != ')')st.push(s[i]);
            else{
                while(st.top() != '('){
                    temp.push_back(st.top());
                    st.pop();
                }
                cout<<temp<<endl;
                st.pop();
                tsz = temp.size();
                for(int j = 0;j <tsz;j++)st.push(temp[j]);
                temp.clear();
            }
            i++;
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};