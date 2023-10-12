/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int mxindex(MountainArray &arr){
        int i = 1,j = arr.length()-2;
        while(i <= j){
            int mid = i + (j-i)/2;
            if(arr.get(mid) > arr.get(mid-1) && arr.get(mid) > arr.get(mid+1))return mid;
            else if(mid && arr.get(mid-1) > arr.get(mid+1))j = mid-1;
            else i = mid+1;
        }
        return -1;
    }

    int binarysearch1(int s,int e,int target,MountainArray &arr){
        while(s <= e){
            int mid = s + (e-s)/2;
            if(arr.get(mid) > target)e = mid - 1;
            else if(arr.get(mid) < target)s = mid + 1;
            else return mid;
        }
        return -1;
    }

    int binarysearch2(int s,int e,int target,MountainArray &arr){
        while(s <= e){
            int mid = s + (e-s)/2;
            if(arr.get(mid) > target)s = mid + 1;
            else if(arr.get(mid) < target)e = mid - 1;
            else return mid;
        }
        return -1;
    }

    int findInMountainArray(int target, MountainArray &arr) {
        int mx = mxindex(arr);
        int s = binarysearch1(0,mx,target,arr);
        if((arr.get(0) > target && arr.get(arr.length()-1) > target) || arr.get(mx) < target)return -1;
        if(s != -1)return s;
        s = binarysearch2(mx+1,arr.length()-1,target,arr);
        if(s != -1)return s;
        return -1;
    }
};