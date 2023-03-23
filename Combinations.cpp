// 77. Combinations
// Medium
// 5.8K
// 180
// Companies
// Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

// You may return the answer in any order.

 

// Example 1:

// Input: n = 4, k = 2
// Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
// Explanation: There are 4 choose 2 = 6 total combinations.
// Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.
// Example 2:

// Input: n = 1, k = 1
// Output: [[1]]
// Explanation: There is 1 choose 1 = 1 total combination.
 

// Constraints:

// 1 <= n <= 20
// 1 <= k <= n
// Accepted
// 651.1K
// Submissions
// 973K
// Acceptance Rate
// 66.9%

//Brute Force
class Solution {
public:
    void c(vector<vector<int>>& v,vector<int> v2,int i,int k,int K,int n){
        if(!k){
            if(v2.size())v.push_back(v2);
            return;
        }
        if(i > n)return;
        v2.push_back(i);
        c(v,v2,i+1,k-1,K,n);
        v2.pop_back();
        c(v,v2,i+1,k,K,n);
        return;
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> v;
        vector<int> v2;
        c(v,v2,1,k,k,n);
        return v;
    }
};

//Little bit optimized
class Solution {
public:
    void c(vector<vector<int>>& v,vector<int>v2,int n,int idx,int k){
        if(!k){
            v.push_back(v2);
            return;
        }
        for(int i = idx;i<=n;i++){
            v2.push_back(i);
            c(v,v2,n,i+1,k-1);
            v2.pop_back();
        }
        return;
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> v;
        vector<int> v2;
        c(v,v2,n,1,k);
        return v;
    }
};