// 4. Median of Two Sorted Arrays
// Hard
// 21.6K
// 2.4K
// Companies
// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

// The overall run time complexity should be O(log (m+n)).

 

// Example 1:

// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2.
// Example 2:

// Input: nums1 = [1,2], nums2 = [3,4]
// Output: 2.50000
// Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

// Constraints:

// nums1.length == m
// nums2.length == n
// 0 <= m <= 1000
// 0 <= n <= 1000
// 1 <= m + n <= 2000
// -106 <= nums1[i], nums2[i] <= 106
// Accepted
// 1.8M
// Submissions
// 4.9M
// Acceptance Rate
// 35.7%

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