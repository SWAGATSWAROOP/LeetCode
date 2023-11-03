class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> v;
        int i = 1;
        int mx = target[target.size()-1];
        for(int j = 0;j<target.size();j++){
            while(i != target[j]){
                v.push_back("Push");
                v.push_back("Pop");
                i++;
            }
            v.push_back("Push");
            i++;
        }
        return v;
    }
};