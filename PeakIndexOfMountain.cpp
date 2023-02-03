// 852. Peak Index in a Mountain Array
// Medium
// 4.6K
// 1.8K
// Companies
// An array arr a mountain if the following properties hold:

// arr.length >= 3
// There exists some i with 0 < i < arr.length - 1 such that:
// arr[0] < arr[1] < ... < arr[i - 1] < arr[i] 
// arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
// Given a mountain array arr, return the index i such that arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].

// You must solve it in O(log(arr.length)) time complexity.

 

// Example 1:

// Input: arr = [0,1,0]
// Output: 1
// Example 2:

// Input: arr = [0,2,1,0]
// Output: 1
// Example 3:

// Input: arr = [0,10,5,2]
// Output: 1
 

// Constraints:

// 3 <= arr.length <= 105
// 0 <= arr[i] <= 106
// arr is guaranteed to be a mountain array.
// Accepted
// 512.9K
// Submissions
// 741K
// Acceptance Rate
// 69.2%


class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int i = 0,n = arr.size()-1,N = arr.size()-1;
        while(i<=n){
            int mid = (i+n)/2;
            if(mid == 0 || mid == N) return mid == 0 ? 1:N-1;
            else if(arr[mid]>arr[mid+1] && arr[mid-1]>arr[mid]){
                n = mid-1;
            }
            else if(arr[mid]<arr[mid+1] && arr[mid-1]<arr[mid]){
                i = mid+1;
            }
            else{
                return mid;
            }
        }
        return -1;
    }
};