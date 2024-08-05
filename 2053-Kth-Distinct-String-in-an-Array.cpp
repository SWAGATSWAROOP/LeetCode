class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> map;
        for(auto x:arr)map[x]++; 
        string ans = "";
        int pos = 0;
        for(auto x:arr){
            if(map[x] == 1 && ++pos == k)ans = x;
        }
        return ans;
    }
};