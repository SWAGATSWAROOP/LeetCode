class Solution {
public:
    int leftsubstr(string s,int n){
        int count = 0;
        for(int i = 0;i<n;i++){
            if(s[i] == '0')count++;
        }
        return count;
    }
    
    int rightsubstr(string s,int n){
        int count = 0;
        for(int i = 0;i<n;i++){
            if(s[i] == '1')count++;
        }
        return count;
    }
    
    int maxScore(string s) {
        int n = s.size();
        int score = 0,left,right;
        for(int i = 1;i<n;i++){
            left = leftsubstr(s.substr(0,i),i);
            right = rightsubstr(s.substr(i,n-i),n-i);
            score = max(score,(left+right));
        }
        return score;
    }
};