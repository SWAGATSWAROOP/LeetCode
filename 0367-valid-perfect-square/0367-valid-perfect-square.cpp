class Solution {
public:
    bool isPerfectSquare(int num) {
    
        int i = 1,j = num;
        while(i<=j){
            int mid = i +(j-i)/2;
            long long l = 1ll*mid*mid;
            if(l > num) j = mid-1;
            else if(l < num) i = mid+1;
            else return true;
        }
        return false;
    }
};