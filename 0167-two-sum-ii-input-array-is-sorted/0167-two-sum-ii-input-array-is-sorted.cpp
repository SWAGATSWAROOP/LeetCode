const static auto initialize = [] { std::ios::sync_with_stdio(false); 
std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();

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
            if(i+1 <= J && numbers[i]+numbers[i+1] > target)break;
        }
        return v;
    }
};