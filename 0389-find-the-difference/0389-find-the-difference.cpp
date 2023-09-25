class Solution {
public:
    char findTheDifference(string s, string t) {
        char v = 0;
        for(char l:s)v ^= l;
        for(char m:t)v ^= m;
        return v; 
    }
};