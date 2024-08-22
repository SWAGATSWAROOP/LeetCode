class Solution {
public:
    int findComplement(int num) {
        int ans = 0;
        int k = 1,rightshift;
        int maxSetbit = 0;
        for(int i = 0;i < 31;i++){
            rightshift = (1 << i);
            if((num & rightshift)){
                maxSetbit = i;
            }
        }
        for(int i = 0;i <= maxSetbit;i++){
            rightshift = (1 << i);
            if(!(num & rightshift)){
                ans = (ans | rightshift);
            }
        }
        return ans;
    }
};