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
    void addLeft(TreeNode* root,TreeNode* add){
        if(!root->left){
            root->left = add;
            return;
        }
        addLeft(root->left,add);
    }

    TreeNode* search(TreeNode* root,int key){
        if(!root)return 0;
        if(key == root->val){
            if(root->right){
                if(root->left)addLeft(root->right,root->left);
                return root->right;
            }
            return root->left;
        }
        if(key > root->val)root->right = search(root->right,key);
        root->left = search(root->left,key);
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        return search(root,key);
    }
};