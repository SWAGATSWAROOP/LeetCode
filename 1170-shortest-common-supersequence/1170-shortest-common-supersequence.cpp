class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        vector<vector<int>> v(str1.size()+1,vector<int>(str2.size()+1,0));
        for(int i = 0;i<str1.size();i++){
            v[i][str2.size()] = str1.size()-i;
        }
        for(int i = 0;i<str2.size();i++){
            v[str1.size()][i] = str2.size()-i;
        }
        for(int i = str1.size()-1;i>=0;i--){
            for(int j = str2.size()-1;j>=0;j--){
                if(str1[i]!=str2[j]){
                    v[i][j] = 1+min(v[i+1][j],v[i][j+1]);
                }
                else v[i][j] = 1+v[i+1][j+1];
            }
        }
        string s ="";
        int i = 0,j = 0;
        while(i < str1.size() && j < str2.size()){
            if(str1[i] != str2[j]){
                if(v[i+1][j] > v[i][j+1])s.push_back(str2[j++]);
                else s.push_back(str1[i++]);
            }
            else{
                s.push_back(str1[i++]);
                j++;
            } 
        }
        if(i < str1.size())s += str1.substr(i);
        if(j < str2.size())s += str2.substr(j);
        return s;
    }
};