/*2448. Minimum Cost to Make Array Equal*/

const static auto initialize = [] { std::ios::sync_with_stdio(false); 
std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();


class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        cout<<n<<endl;
        long  sum = 0;
        vector<pair<int,int>> p;
        for(int i = 0;i<n;i++)p.push_back(make_pair(nums[i],cost[i]));
        sort(p.begin(),p.end());
        for(auto x:cost)sum += x;
        long target = (sum+1)/2;
        long  k = 0;
        for(int i = 0;i<n;i++){
            k += p[i].second;
            if(k >= target){
                target = p[i].first;
                break;
            }
        }
        sum = 0;
        for(int i = 0;i<n;i++)sum += 1ll*abs(1ll*target-1ll*p[i].first) * 1ll*p[i].second;
        return sum;
    }
    //  long long minCost(vector<int>& nums, vector<int>& cost) {
    //    int n = nums.size();
    //    vector<pair<int,int>>arr;
    //    long long sum = 0;
    //    for(int i=0;i<n;i++){
    //        arr.push_back({nums[i],cost[i]});
    //        sum += cost[i];
    //    }
    //    sort(arr.begin(),arr.end());
    //    long long N = (sum+1)/2;
    //    int x = -1;
    //    for(int i=0;i<n;i++){
    //        N -= arr[i].second;
    //        if(N<=0){
    //         x = arr[i].first;
    //         break;
    //        }
    //    }
    //  long long ans = 0;
    //  for(int i=0;i<n;i++){
    //   ans += (long long)abs( (long long) x*cost[i]-(long long) nums[i]*cost[i]);   
    //  }
    //  return ans;
    // }
};
Hard
1.9K
23
Companies
You are given two 0-indexed arrays nums and cost consisting each of n positive integers.

You can do the following operation any number of times:

Increase or decrease any element of the array nums by 1.
The cost of doing one operation on the ith element is cost[i].

Return the minimum total cost such that all the elements of the array nums become equal.

 

Example 1:

Input: nums = [1,3,5,2], cost = [2,3,1,14]
Output: 8
Explanation: We can make all the elements equal to 2 in the following way:
- Increase the 0th element one time. The cost is 2.
- Decrease the 1st element one time. The cost is 3.
- Decrease the 2nd element three times. The cost is 1 + 1 + 1 = 3.
The total cost is 2 + 3 + 3 = 8.
It can be shown that we cannot make the array equal with a smaller cost.
Example 2:

Input: nums = [2,2,2,2,2], cost = [4,2,8,1,3]
Output: 0
Explanation: All the elements are already equal, so no operations are needed.
 

Constraints:

n == nums.length == cost.length
1 <= n <= 105
1 <= nums[i], cost[i] <= 106
Accepted
47.7K
Submissions
104.9K
Acceptance Rate
45.5%*/
