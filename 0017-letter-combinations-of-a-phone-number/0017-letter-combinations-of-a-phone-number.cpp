class Solution {
public: 
    unordered_map<char,string> map;

    void letter(vector<string>& v,string digits){
        if(digits.length() == 1){
            string o = map[digits[0]];
            int l = o.length();
            for(int i=0;i<l;i++){
                v.push_back("");
                v[i] += o[i]; 
            }
            return;
        }
        letter(v,digits.substr(1));
        int k = v.size();
        int l = map[digits[0]].length();
        for(int i = 1;i<l;i++){
            for(int j = 0;j<k;j++){
                v.push_back(v[j]);
            }
        }
        for(int i=0;i<l;i++){
            for(int j=0;j<k;j++){
                v[k*i + j] = map[digits[0]][i] + v[j+i*k];
            }
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        vector<string> v;
        if(digits.length()==0){
            return v;
        }
        map['2'] = "abc";
        map['3'] = "def";
        map['4'] = "ghi";
        map['5'] = "jkl";
        map['6'] = "mno";
        map['7'] = "pqrs";
        map['8'] = "tuv";
        map['9'] = "wxyz";
        letter(v,digits);
        return v;
    }
};