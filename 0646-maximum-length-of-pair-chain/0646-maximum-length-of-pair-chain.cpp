class Solution {
public:
    static bool comp(vector<int> s,vector<int> e){
        return s[1]<e[1];
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),comp);
        int n = pairs.size();
        int count = 1;
        int l = pairs[0][1];
        for(int i = 1;i<n;i++){
            if(l<pairs[i][0]){
                count++;
                l = pairs[i][1];
            }
        }
        return count;
    }
};