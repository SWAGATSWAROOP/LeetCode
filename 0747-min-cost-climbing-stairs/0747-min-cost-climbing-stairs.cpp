class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev1 = cost[0],prev2 = cost[1];
        for(int i = 2;i<cost.size();i++){
            int ans = cost[i] + min(prev1,prev2);
            prev1 = prev2;
            prev2 = ans;
        }
        return min(prev2,prev1);
    }
};