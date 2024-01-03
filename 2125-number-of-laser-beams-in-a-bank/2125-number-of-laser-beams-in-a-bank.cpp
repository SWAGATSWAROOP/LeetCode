class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int row = bank.size(),col = bank[0].size();
        int prev = 0,curr = 0,ans = 0;
        for(int j = 0;j<col;j++){
            if(bank[0][j] == '1')prev++;
        }
        for(int i = 1;i < row;i++){
            curr = 0;
            for(int j = 0;j<col;j++){
                if(bank[i][j] == '1')curr++;
            }
            if(curr){
                ans += curr*prev;
                prev = curr;
            }
        }
        return ans;
    }
};