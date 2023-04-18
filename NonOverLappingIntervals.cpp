// 5. Non-overlapping Intervals
// Medium
// 5.7K
// 156
// Companies
// Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

 

// Example 1:

// Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
// Output: 1
// Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
// Example 2:

// Input: intervals = [[1,2],[1,2],[1,2]]
// Output: 2
// Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.
// Example 3:

// Input: intervals = [[1,2],[2,3]]
// Output: 0
// Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
 

// Constraints:

// 1 <= intervals.length <= 105
// intervals[i].length == 2
// -5 * 104 <= starti < endi <= 5 * 104
// Accepted
// 356.3K
// Submissions
// 708.1K
// Acceptance Rate
// 50.3%

class Solution {
public:
    static bool comp(vector<int>& v,vector<int>& u){
        return v[1]<u[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count = -1,n = intervals.size();
        if(!n)return 0;
        sort(intervals.begin(),intervals.end(),comp);
        vector<int> prev = intervals[0];
        for(vector<int> x:intervals){
            if(prev[1]<=x[0])prev = x;
            else count++;
        }
        return count;
    }
};