// 135. Candy
// Hard
// 5.2K
// 341
// Companies
// There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

// You are giving candies to these children subjected to the following requirements:

// Each child must have at least one candy.
// Children with a higher rating get more candies than their neighbors.
// Return the minimum number of candies you need to have to distribute the candies to the children.

 

// Example 1:

// Input: ratings = [1,0,2]
// Output: 5
// Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
// Example 2:

// Input: ratings = [1,2,2]
// Output: 4
// Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
// The third child gets 1 candy because it satisfies the above two conditions.
 

// Constraints:

// n == ratings.length
// 1 <= n <= 2 * 104
// 0 <= ratings[i] <= 2 * 104
// Accepted
// 298.7K
// Submissions
// 729.4K
// Acceptance Rate
// 41.0%

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size(),count = 0;
        vector<int> v1(n,1);
        for(int i = 1;i<n;i++){
            if(ratings[i]>ratings[i-1]) v1[i] = v1[i-1]+1;
        }
        vector<int> v2(n,1);
        for(int j = n-2;j>=0;j--){
            if(ratings[j]>ratings[j+1]) v2[j] = v2[j+1]+1;  
        }
        for(int i=0;i<n;i++) count += max(v1[i],v2[i]);
        return count;
    }
};