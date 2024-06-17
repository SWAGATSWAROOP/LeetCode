class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c <= 2)return true;
        int mx = sqrt(c),ans2;
        double ans1;
        int diff;
        for(int i = 1;i <= mx;i++){
            diff = c - (i*i);
            if(diff < 0)return false;
            ans1 = sqrt(diff);
            ans2 = ans1;
            if(ans1 == ans2)return true;
        }
        return false;
    }
};