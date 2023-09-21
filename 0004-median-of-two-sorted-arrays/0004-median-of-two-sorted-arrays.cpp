class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int sum = m+n;
        vector<int> nums3;
        int i = 0,j = 0;
        while(i<m && j<n){
            if(nums1[i] > nums2[j]){
                nums3.push_back(nums2[j++]);
            }
            else{
                nums3.push_back(nums1[i++]);
            }
        }
        for(;i<m;i++){
            nums3.push_back(nums1[i]);
        }
        for(;j<n;j++){
            nums3.push_back(nums2[j]);
        }
        if(sum%2==0){
            sum /= 2;
            return (double)(nums3[sum]+nums3[sum-1])/2.0;
        }
        else{
            sum /= 2;
            return (double)(nums3[sum]);
        }
    }
};