const static auto initialize = [] { std::ios::sync_with_stdio(false); 
std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();
class Solution {
public:
    bool isValid(vector<int>& p,int h,int mid,int n){
        int sum = 0;
        for(int i = 0;i<n;i++){
            sum += ceil((1.0*p[i])/mid);
            if(sum > h)return false;
        }
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int start = 1,end = *max_element(piles.begin(),piles.end());
        int res = end;
        while(start <= end && n != h){
            int mid = (start+end)/2;
            if(isValid(piles,h,mid,n)){
                res = mid;
                end = mid - 1;
            }
            else start = mid+1;
        }
        return res;
    }
};