class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(),m = word2.size();
        vector<int> v(n+1,0);
        for(int i = n-1;i>=0;i--)v[i] = 1 + v[i+1];
        for(int j = m-1;j>=0;j--){
            int prev = v[n];
            v[n] += 1;  
            for(int i = n-1;i>=0;i--){
                int temp = v[i];
                if(word1[i] == word2[j])v[i] = prev;
                else v[i] = min(1+v[i],1+v[i+1]);
                prev = temp; 
            }
        }
        return v[0];
    }
};