class Solution {
public:


    long long minimumReplacement(vector<int>& nums) {
        long long ans = 0,prevmin = nums[nums.size()-1];
        for(int i = nums.size()-2;i>=0;i--){
            if(nums[i] > prevmin){
                double l = (1.0*nums[i])/prevmin;
                cout<<l<<" ";
                int a  = l;
                cout<<a<<" "<<i<<endl;
                if(a == l)a--;
                prevmin = nums[i]/ceil(l);
                ans += a;
            }
            else prevmin = nums[i];
        }
        return ans;
    }
};