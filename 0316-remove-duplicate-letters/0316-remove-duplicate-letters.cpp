class Solution {
public:
    string removeDuplicateLetters(string s) {
        string g;
        unordered_map<char,int> map;
        vector<int> v(26,0);
        for(int i = 0;i < s.size();i++)map[s[i]] += 1;
        for(int i = 0;i<s.size();i++){
            if(!v[s[i]-'a']){
                while(!(g.empty()) && (g.back() > s[i]) && map[g.back()]){
                    v[g.back()-'a'] = false;
                    g.pop_back();
                }
                g.push_back(s[i]);
                v[s[i]-'a'] = true;
            }
            map[s[i]]--;
        }
        return g;
    }
};