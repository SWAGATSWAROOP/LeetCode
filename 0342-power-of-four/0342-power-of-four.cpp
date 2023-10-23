class Solution {
public:
    bool isPowerOfFour(int n) {
        int count = 16;
        int num = 1;
        while(count--){
            if((num ^ n) == 0)return true;
            num <<= 2;
        }
        return false;
    }
};