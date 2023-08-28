#include<cmath>
class Solution {
public:
    int mySqrt(int x) {
        if( x == 0 || x == 1){
            return x;
        }
        long long start = 1;
        long long end = x/2;
        long long ans;
        while(start <= end){
            long long mid = (start+end)/2;
            long long l = mid * mid;
            if(l == x){
                return mid;
            }
            else if(l <= x){
                start = mid+1;
                ans = mid;
            }
            else{
                end = mid - 1;
            }
        }
        return ans;
    }
};