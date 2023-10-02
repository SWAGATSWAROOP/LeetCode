class Solution {
public:
    bool winnerOfGame(string s) {
        int countA = 0,countB = 0,n = s.size()-1;
        for(int i = 1;i<n;i++){
            if(s[i] == 'A' && s[i-1] =='A' && s[i+1] == 'A')countA++;
            else if(s[i] == 'B' && s[i-1] == 'B' && s[i+1] == 'B')countB++;
        }
        cout<<countA<<" "<<countB<<endl;
        return countA > countB;
    }
};