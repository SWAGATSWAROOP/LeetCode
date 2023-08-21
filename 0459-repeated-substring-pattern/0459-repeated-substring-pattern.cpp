class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if(s.size() == 1)return false;
        int mid = s.size() & 1 ? (s.size()-1)/2 : s.size()/2;
        int k = s.size() & 1 ? 1:0;
        while(k < s.size()){
            if(s.substr(0,mid) == s.substr(mid,mid) && s.substr(k,mid) == s.substr(k+mid,mid) && s.substr(0,mid) == s.substr(k,mid))return true;
            k += 2;
            mid = (s.size()-k)/2;
        }
    return false;
    }
};