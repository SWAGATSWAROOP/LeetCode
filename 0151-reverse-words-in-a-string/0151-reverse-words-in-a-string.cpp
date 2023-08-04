class Solution {
public:
    string reverseWords(string s) {
        int j = s.size()-1,i = 0;
        while(s[j] == ' '){
            s.pop_back();
            j--;
        }
        while(s[0] == ' '){
            s.erase(s.begin());
            j--;
        }
        while(i < j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
        i = 0,j = 0;
        for(;j < s.size();j++){
            if(j == s.size()-1 || s[j] == ' '){
                int k = j == s.size()-1 ? j : j-1;
                while(i<k){
                    swap(s[i++],s[k--]);
                }
                i = j+1;
                while(i < s.size() && s[i] == ' '){
                    s.erase(s.begin()+i);
                }
            }
        }
        return s;
    }
};