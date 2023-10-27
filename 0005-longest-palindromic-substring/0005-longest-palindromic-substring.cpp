class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n == 1)return s;
        vector<vector<int>> v(n,vector<int>(n,0));
        int row,mx = INT_MIN;
        for(int j = 0;j<2;j++){
            int k = j;
            for(int i=0;k<n;i++,k++){
                if(s[i] == s[k])v[i][k] = 1;
                else v[i][k] = 0;
                int sl = k-i+1;
                if(v[i][k] && mx < sl){
                    row = i;
                    mx = sl;
                }
            }
        }
        for(int j = 2;j<n;j++){
            int k = j;
            for(int i=0;k<n;i++,k++){
                if(s[i] == s[k] && v[i+1][k-1])v[i][k] = 1;
                else v[i][k] = 0;
                int sl = k-i+1;
                if(v[i][k] && mx < sl){
                    row = i;
                    mx = sl;
                }
            }
        }
        string sg;
        while(mx--){
            sg.push_back(s[row]);
            row++;
        }
        return sg;
    }
};