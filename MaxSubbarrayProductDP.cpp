//Recursion

class Solution {
public:
    pair<int,pair<int,int>> mxP(vector<int>& nums,int i,int n){
        if(i == n)return make_pair(INT_MIN,make_pair(1,1));
        pair<int,pair<int,int>> k = mxP(nums,i+1,n);
        if(nums[i] >= 0){
            k.second.first = max(nums[i],nums[i]*k.second.first);
            k.second.second *= nums[i];
        }
        else{
            int l = k.second.first;
            k.second.first = k.second.second*nums[i];
            k.second.second = min(nums[i],nums[i]*l);
        } 
        k.first = max(k.first,k.second.first);
        return k;
    }

    int maxProduct(vector<int>& nums) {
        return mxP(nums,0,nums.size()).first;
    }
};

//Tabulation

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(),k = INT_MIN;
        vector<pair<int,int>> v(n+1);
        v[n] = make_pair(1,1);
        for(int i = n-1;i>=0;i--){
            if(nums[i] >= 0){
                v[i].first = max(nums[i],nums[i]*v[i+1].first);
                v[i].second = nums[i]*v[i+1].second;
            }
            else{
                v[i].first = v[i+1].second*nums[i];
                v[i].second = min(nums[i],nums[i]*v[i+1].first);
            }
            k = max(k,v[i].first);
        }
        return k;
    }
};

//With Space Optimization
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(),k = INT_MIN,mn = 1,mx = 1;
        for(int i = n-1;i>=0;i--){
            if(nums[i] >= 0){
                mx = max(nums[i],nums[i]*mx);
                mn = nums[i]*mn;
            }
            else{
                int temp = mx;
                mx = mn*nums[i];
                mn = min(nums[i],nums[i]*temp);
            }
            k = max(k,mx);
        }
        return k;
    }
};
