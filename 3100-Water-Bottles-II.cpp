class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = numBottles,emptyBottle = ans,q;
        while(emptyBottle >= numExchange){
            ans += 1;
            emptyBottle -= (numExchange - 1);
            numExchange++;
        }
        return ans;
    }
};