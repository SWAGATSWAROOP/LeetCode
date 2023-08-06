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
    map <pair<int,int>,vector<TreeNode*>> map;

    vector<TreeNode*> generateTrees(int n,int s = 1) {
        pair<int,int> p(n,s);
        if(map.find(p)!=map.end())return map[p];
        if(n < s)return {NULL};
        vector<TreeNode*> v;
        for(int i = s;i<=n;i++){
            for(auto l:generateTrees(i-1,s)){
                for(auto r:generateTrees(n,i+1)){
                    v.push_back(new TreeNode(i,l,r));
                }
            }
        }
        return map[p] = v;
    }
};