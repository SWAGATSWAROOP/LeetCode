// 	95. Unique Binary Search Trees II
// Medium
// 5.9K
// 379
// Companies
// Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. Return the answer in any order.

 

// Example 1:


// Input: n = 3
// Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
// Example 2:

// Input: n = 1
// Output: [[1]]
 

// Constraints:

// 1 <= n <= 8
// Accepted
// 351.3K
// Submissions
// 669.4K
// Acceptance Rate
// 52.5%
    
    class Solution {
	public:
		vector<TreeNode*> generateTrees(int n, int s = 1) {
			vector<TreeNode*> ans;
			if(n < s) return {nullptr};                              
			 for(int i=s; i<=n; i++) {                	                 // Consider every number in range [s,n] as root  
				for(auto left: generateTrees(i-1, s)) {                  // generate all possible trees in range [s,i)
					for(auto right: generateTrees(n, i+1))               // generate all possible trees in range (i,e]
						ans.push_back(new TreeNode(i, left, right));     // make new trees with i as the root 
				}
			}
			return ans;
		}
	};