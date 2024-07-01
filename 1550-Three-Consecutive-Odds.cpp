class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int sz = arr.size();
        if(sz < 3)return false;
        int i = 0,j = 0,count = 0;
        while(j <= 2){
            if(arr[j] & 1)count++;
            j++;
        }
        if(count == 3)return true;
        while(j < sz){
            if(arr[i] & 1)count--;
            if(arr[j] & 1)count++;
            if(count == 3)return true;
            i++;
            j++;
        }
        return false;
    }
};