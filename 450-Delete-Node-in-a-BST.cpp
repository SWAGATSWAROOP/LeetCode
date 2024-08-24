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
            TreeNode* left = root->left;
            TreeNode* right = root->right;
            root->left = 0;
            root->right = 0;
            delete root;
            if(right){
                if(left)addLeft(right,left);
                return right;
            }
            return left;
        }
        if(key > root->val)root->right = search(root->right,key);
        root->left = search(root->left,key);
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        return search(root,key);
    }
};