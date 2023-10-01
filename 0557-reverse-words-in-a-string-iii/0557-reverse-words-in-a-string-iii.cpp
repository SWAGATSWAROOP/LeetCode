class Solution {
public:
    string reverseWords(string s) {
        for(int i = 0;i<s.size();){
            int k = i;
            while(k < s.size() && s[k] != ' ')k++;
            int j = i,z = k+1;
            k--;
            while(j < k){
                swap(s[j],s[k]);
                j++;
                k--;
            }
            while(z < s.size() && s[z] == ' ')z++;
            i = z;
        }
        return s;
    }
};