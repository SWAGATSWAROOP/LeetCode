// LeetCode Logo
// Problem List
// Premium
// 1

// avatar
// Description
// Editorial
// Solutions (2.3K)
// Submissions
// 60. Permutation Sequence
// Hard
// 5.4K
// 432
// Companies
// The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

// By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

// "123"
// "132"
// "213"
// "231"
// "312"
// "321"
// Given n and k, return the kth permutation sequence.

 

// Example 1:

// Input: n = 3, k = 3
// Output: "213"
// Example 2:

// Input: n = 4, k = 9
// Output: "2314"
// Example 3:

// Input: n = 3, k = 1
// Output: "123"
 

// Constraints:

// 1 <= n <= 9
// 1 <= k <= n!
// Accepted
// 319.9K
// Submissions
// 721.6K
// Acceptance Rate
// 44.3%


class Solution {
public:
    string per(int arr[],string g,int k){
        if(k == 1 || k == 0)return g;
        int m = arr[g.size()-1];
        float l = (float)k/m;
        int o = (int)l;
        if(m == 1 || l == o)o--;
        char s = g[o];
        for(int i = o;i>0;i--)g[i] = g[i-1];
        g = per(arr,g.substr(1),k - o*m);
        g = s + g;
        return g;
    }

    string getPermutation(int n, int k) {
        string g = "";
        for(int i = 1;i<=n;i++)g += i+48;
        int arr[10];
        arr[0] = 1;
        for(int i = 1;i<10;i++)arr[i] = arr[i-1]*(i);
        return per(arr,g,k);
    }
};