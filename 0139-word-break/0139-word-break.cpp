class Solution {
public:
    int si(string& s,vector<string>& wordDict,int i,vector<int>& v){
        if(i == s.size())return 1;
        if(v[i] != -1)return v[i];
        string temp = "";
        for(int j = i;j<s.size();j++){
            temp += s[j];
            if(find(wordDict.begin(),wordDict.end(),temp) != wordDict.end())if(si(s,wordDict,j+1,v))return v[i] = 1;
        }
        return v[i] = 0;
    }

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