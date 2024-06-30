class Solution {
public:
    int minBitFlips(int start, int goal) {
        int num = start ^ goal,count = 0;
        while(num){
            if(num & 1)count++;
            num >>= 1;
        }
        return count;
    }
};