class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0,n = details.size();
        for(int i = 0;i < n;i++){
            if((details[i][11] >= '6' && details[i][11] <= '9' && details[i][12] > '0') || (details[i][11] >= '7' && details[i][11] <= '9' && details[i][12] >= '0'))count++;
        }
        return count;
    }
};