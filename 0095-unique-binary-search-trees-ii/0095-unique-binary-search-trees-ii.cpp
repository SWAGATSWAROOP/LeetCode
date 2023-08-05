/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n,int mn = 1) {
        if(mn > n)return {NULL};
        vector<TreeNode*> v;
        for(int i = mn;i<=n;i++){
            for(auto l:generateTrees(i-1,mn)){
                for(auto r:generateTrees(n,i+1)){
                    v.push_back(new TreeNode(i,l,r));
                }
            }
        }
        return v;
    }
};