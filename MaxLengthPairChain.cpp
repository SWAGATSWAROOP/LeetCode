// 46. Maximum Length of Pair Chain
// Medium
// 2.9K
// 113
// Companies
// You are given an array of n pairs pairs where pairs[i] = [lefti, righti] and lefti < righti.

// A pair p2 = [c, d] follows a pair p1 = [a, b] if b < c. A chain of pairs can be formed in this fashion.

// Return the length longest chain which can be formed.

// You do not need to use up all the given intervals. You can select pairs in any order.

 

// Example 1:

// Input: pairs = [[1,2],[2,3],[3,4]]
// Output: 2
// Explanation: The longest chain is [1,2] -> [3,4].
// Example 2:

// Input: pairs = [[1,2],[7,8],[4,5]]
// Output: 3
// Explanation: The longest chain is [1,2] -> [4,5] -> [7,8].
 

// Constraints:

// n == pairs.length
// 1 <= n <= 1000
// -1000 <= lefti < righti <= 1000
// Accepted
// 133.2K
// Submissions
// 235.6K
// Acceptance Rate
// 56.5%

class Solution {
public:
    static bool comp(vector<int> s,vector<int> e){
        return s[1]<e[1];
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),comp);
        int n = pairs.size();
        int count = 1;
        int l = pairs[0][1];
        for(int i = 1;i<n;i++){
            if(l<pairs[i][0]){
                l = pairs[i][1];
                count++;
            }
        }
        return count;
    }
};