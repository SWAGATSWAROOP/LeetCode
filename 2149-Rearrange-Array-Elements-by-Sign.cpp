class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n,0);
        int ip = 0,in = 1;
        for(int i = 0;i < n;i++){
            if(nums[i] > 0){
                v[ip] = nums[i];
                ip += 2;
            }
            else{
                v[in] = nums[i];
                in += 2;
            }
        }
        return v;
    }
};