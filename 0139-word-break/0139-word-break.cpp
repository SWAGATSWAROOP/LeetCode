class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> v(s.size()+1,0);
        v[s.size()] = 1;
        string temp ="";
        for(int i = s.size()-1;i>=0;i--){
            string temp = "";
            for(int j = i;j<s.size();j++){
                temp += s[j];
                if(find(wordDict.begin(),wordDict.end(),temp) != wordDict.end() && v[j+1])v[i] = v[j+1];
            }
        }
        return v[0];
    }
};