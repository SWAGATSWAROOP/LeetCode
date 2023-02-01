// 56. Merge Intervals
// Medium
// 17.9K
// 616
// Companies
// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

// Example 1:

// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
// Example 2:

// Input: intervals = [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 

// Constraints:

// 1 <= intervals.length <= 104
// intervals[i].length == 2
// 0 <= starti <= endi <= 104
// Accepted
// 1.8M
// Submissions
// 3.9M
// Acceptance Rate
// 46.1%

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> v;
        vector<int> v2 = intervals[0];
        int i = 1;
        int n = intervals.size();
        while(i<n){
            if(v2[1] >= intervals[i][0]){
                v2[1] = max(v2[1],intervals[i][1]);
            }
            else{
                v.push_back(v2);
                v2 = intervals[i];
            }
            i++;
        }
        v.push_back(v2);
        return v;
    }
};