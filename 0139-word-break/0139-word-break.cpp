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
        return  v[i] = 0;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> v(s.size(),-1);
        return si(s,wordDict,0,v);
    }
};