class Solution {
public:
    int num(int bottle,int ex){
        if(bottle < ex)return 0;
        int b = bottle/ex;
        int c = bottle%ex;
        return b + num(b+c,ex);
    }

    int numWaterBottles(int numBottles, int numExchange) {
        return numBottles + num(numBottles,numExchange);
    }
};