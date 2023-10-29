class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int c1 = 0,c2 = 0;
        while(s.size() || t.size()){
            while(s.size() && s.back() == '#'){
                s.pop_back();
                c1++;
            }
            while(s.size() && c1){
                if(s.back() == '#')break;
                s.pop_back();
                c1--;
            }
            while(t.size() && t.back() == '#'){
                t.pop_back();
                c2++;
            }
            while(t.size() && c2){
                if(t.back() == '#')break;
                t.pop_back();
                c2--;
            }
            if((!s.size() && t.size() && t.back() != '#') || (!t.size() && s.size() && s.back() != '#'))return false;
            else if(s.size() && t.size() && s.back() != '#' && t.back() != '#'){
                if(s.back() != t.back())return false;
                s.pop_back();
                t.pop_back();
            }
        }
        return true;
    }
};