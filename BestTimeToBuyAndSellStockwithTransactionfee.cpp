// 714. Best Time to Buy and Sell Stock with Transaction Fee
// Medium
// 6.3K
// 167
// Companies
// You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

// Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

// Example 1:

// Input: prices = [1,3,2,8,4,9], fee = 2
// Output: 8
// Explanation: The maximum profit can be achieved by:
// - Buying at prices[0] = 1
// - Selling at prices[3] = 8
// - Buying at prices[4] = 4
// - Selling at prices[5] = 9
// The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
// Example 2:

// Input: prices = [1,3,7,5,10,3], fee = 3
// Output: 6
 

// Constraints:

// 1 <= prices.length <= 5 * 104
// 1 <= prices[i] < 5 * 104
// 0 <= fee < 5 * 104
// Accepted
// 278.9K
// Submissions
// 414.7K
// Acceptance Rate
// 67.3%

//Recursion On mY own
class Solution {
public:
    int mxP(vector<int>& p,int i,int n,int prev,int fee){
        if(i == n)return 0;
        int l = 0;
        if(!prev)l = mxP(p,i+1,n,p[i]+fee,fee);
        else if(prev <= p[i])l = p[i]-prev + mxP(p,i+1,n,0,fee);
        int k = mxP(p,i+1,n,prev,fee);
        return max(l,k);
    }

    int maxProfit(vector<int>& prices, int fee) {
        return mxP(prices,0,prices.size(),0,fee);
    }
};

//Memotization on my own but got TLE
class Solution {
public:
    int mxP(vector<int>& p,int i,int n,int prev,int fee,vector<vector<int>>& v){
        if(i == n)return 0;
        if(v[prev+1][i]!=-1)return v[prev+1][i];
        int l = 0;
        if(prev == -1)l = mxP(p,i+1,n,i,fee,v);
        else if(p[prev] + fee <= p[i])l = p[i]- p[prev] - fee + mxP(p,i+1,n,-1,fee,v);
        int k = mxP(p,i+1,n,prev,fee,v);
        return v[prev+1][i] = max(l,k);
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> v(n+1,vector<int>(n,-1));
        return mxP(prices,0,n,-1,fee,v);
    }
};