class Solution {
public:
    int countPrimes(int n) {
        vector<int> arr(n,0);
        int count = 0;
        for(int i = 2;i*i<n;i++){
            if(arr[i])continue;
            for(int j = i*i;j < n;j += i)arr[j] = 1;
        }
        for(int i = 2;i<n;i++){
            if(!arr[i])count++;
        }
        return count;
    }
};