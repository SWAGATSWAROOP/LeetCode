class Solution {
public:
    int climbStairs(int n) {
        int prev0 = 1;
        int prev1 = 1;
        int temp;
        for(int i = 2;i <= n;i++){
            temp = prev1 + prev0;
            prev0 = prev1;
            prev1 = temp; 
        }
        return prev1;
    }
};