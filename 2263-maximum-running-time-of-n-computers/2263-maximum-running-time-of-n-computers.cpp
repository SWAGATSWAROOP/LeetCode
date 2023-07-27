class Solution {
public:
    bool poss(int n, vector<int>& batteries,long long  mid){
        long long totTime = mid*n;
        
        for(long long bTime : batteries)
            totTime -= min(mid,bTime);
        
        return (totTime <= 0);
    }

    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum = 0,mx = INT_MAX;
        for(long long x:batteries){
            sum += x;
            mx = min(mx,x);
        }
        long long i = mx,j = sum,ans = mx;
        while(i <= j){
            long long mid = i + (j-i)/2;
            if(poss(n,batteries,mid)){
                ans = mid;
                i = mid + 1;
            }
            else j = mid - 1;
        }
        return ans;
    }
};