class Solution {
public:
    unordered_map<char,string> map;

    void C(vector<string>& v,string s,int i,string digits){
        if(i == digits.size()){
            v.push_back(s);
            return;
        }
        cout<<map[digits[i]]<<endl;
        for(int j = 0;j<map[digits[i]].size();j++){
            s.push_back(map[digits[i]][j]);
            C(v,s,i+1,digits);
            s.pop_back();
        }
        return;
    }

    vector<string> letterCombinations(string digits) {
        vector<string> v;
        if(!digits.size())return v;
        map['2'] = "abc";
        map['3'] = "def";
        map['4'] = "ghi";
        map['5'] = "jkl";
        map['6'] = "mno";
        map['7'] = "pqrs";
        map['8'] = "tuv";
        map['9'] = "wxyz"; 
        C(v,"",0,digits);
        return v;
    }
};