class Solution {
public:
    string sortVowels(string s) {
        string g = s;
        sort(g.begin(),g.end());
        cout<<g<<endl;
        int j = 0,i = 0;
         while(j < g.size() && (g[j] != 'A' && g[j] != 'E' && g[j] != 'I' && g[j] != 'O' && g[j] != 'U' && g[j] != 'a' && g[j] != 'i' && g[j] != 'o' && g[j] != 'e' && g[j] != 'u'))j++;
        while(i<s.size()){
            while(i < s.size() && (s[i]!='A' && s[i]!= 'E' && s[i]!= 'I' && s[i]!= 'O' && s[i]!= 'U' && s[i]!= 'a' && s[i]!= 'i' && s[i]!= 'o' && s[i]!= 'e' && s[i]!= 'u'))i++;
            s[i] = g[j];
            i++;
            j++;
            while(j < g.size() && (g[j] != 'A' && g[j] != 'E' && g[j] != 'I' && g[j] != 'O' && g[j] != 'U' && g[j] != 'a' && g[j] != 'i' && g[j] != 'o' && g[j] != 'e' && g[j] != 'u'))j++;
        }
        return s;
    }
};