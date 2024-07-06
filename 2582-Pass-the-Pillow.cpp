class Solution {
public:
    int passThePillow(int n, int time) {
        int i = 1;
        int dir = 1;
        while(time--){
            if(i == 1){
                dir = 1;
                i++;
            }else if(i == n){
                dir = 0;
                i--;
            }
            else if(dir == 1)i++;
            else i--;
        }
        return i;
    }
};