const static auto initialize = [] { std::ios::sync_with_stdio(false); 
std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();

class Solution {
public:
    int ans = INT_MAX;
    void dc(vector<int>& cookies,vector<int>& bags,int n,int index,int k,int fair){
        if(index == n){
            int l  = *max_element(bags.begin(),bags.end());
            ans = min(ans,l); 
            return;   
        }
        for(int i = 0;i<k;i++){
            if(fair <= bags[i])continue;
            bags[i] += cookies[index];
            dc(cookies,bags,n,index+1,k,fair);
            bags[i] -= cookies[index];
        }
        return;
    }

    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
        vector<int> bags(k,0);
        int sum = accumulate(cookies.begin(),cookies.end(),0);
        sort(cookies.begin(),cookies.end(),greater<int>());
        int fair = ceil(1.0*sum)/k;
        dc(cookies,bags,n,0,k,fair);
        return ans;
    }
};