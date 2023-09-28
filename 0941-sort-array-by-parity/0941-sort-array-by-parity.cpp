class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0;
        while(i < nums.size() && (nums[i] & 1) == 0)i++;
        cout<<i<<endl;
        for(int j = i+1;j<nums.size();j++){
            cout<<j<<endl;
            if((nums[j] & 1) == 0){
                cout<<"YES "<<i<<endl;
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++;
            }
        }
        return nums;
    }
};