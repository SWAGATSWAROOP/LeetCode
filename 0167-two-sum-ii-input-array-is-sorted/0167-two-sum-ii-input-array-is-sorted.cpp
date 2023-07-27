class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> v;
        int i = 0,J = numbers.size()-1;
        
        while(i<=J){
            int j = i+1,n = J,t = target-numbers[i];
            while(j<=n){
                int mid = j + (n-j)/2;
                if(numbers[mid] > t)n = mid - 1;
                else if(numbers[mid] < t)j = mid + 1;
                else{
                    v.push_back(i+1);
                    v.push_back(mid+1);
                    return v;
                }
            }
            i++;
            if((target < 0 && numbers[i] > 0) || (target > 0 && numbers[i] > target))break;
        }
        return v;
    }
};