class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        const static auto initialize = [] { std::ios::sync_with_stdio(false); 
        std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();

        stack<int> st;
        vector<int> v(temperatures.size(),0);
        st.push(0);
        for(int i = 1;i<temperatures.size();i++){
            while(!st.empty() && temperatures[st.top()] < temperatures[i]){
                v[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return v;
    }
};