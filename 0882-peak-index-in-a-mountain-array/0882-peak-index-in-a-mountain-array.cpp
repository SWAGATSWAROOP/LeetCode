class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size()-1,i = 0,N = n;
        while(i<=n){
            int mid = i+(n-i)/2;
            if(mid == 0 || mid == N)return mid == 0 ? 1:N-1;
            if(arr[mid] > arr[mid+1] && arr[mid-1] > arr[mid])n = mid - 1;
            else if(arr[mid] > arr[mid-1] && arr[mid+1] > arr[mid])i = mid+1;
            else return mid;
        }
        return -1;
    }
};