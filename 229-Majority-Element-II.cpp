class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int cn1 = 0,cn2 = 0,n = nums.size(),ele1 = INT_MIN,ele2 = INT_MIN;
        for(int i = 0;i < n;i++){
            if(!cn1 && nums[i] != ele2){
                cn1 = 1;
                ele1 = nums[i];
            }
            else if(!cn2 && nums[i] != ele1){
                cn2 = 1;
                ele2 = nums[i];
            }
            else if(nums[i] == ele1)cn1++;
            else if(nums[i] == ele2)cn2++;
            else{
                cn1--;
                cn2--;
            }
        }
        int mini = n/3 + 1;
        cn1 = 0,cn2 = 0;
        for(int i = 0;i < n;i++){
            if(nums[i] == ele1)cn1++;
            else if(nums[i] == ele2)cn2++;
        }
        if(cn1 >= mini)ans.push_back(ele1);
        if(cn2 >= mini)ans.push_back(ele2);
        return ans;
    }
};