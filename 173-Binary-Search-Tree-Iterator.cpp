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
void inorder(TreeNode* root,vector<int>& v){
    if(!root)return;
    inorder(root->left,v);
    v.push_back(root->val);
    inorder(root->right,v);
} 

class BSTIterator {
public:
    vector<int> v;
    int i;
    int sz;
    BSTIterator(TreeNode* root) {
        inorder(root,this->v);  
        this->i = -1;  
        this->sz = this->v.size();
    }
    
    int next() {
        this->i++;
        return v[i];
    }
    
    bool hasNext() {
        return this->i >= this->sz-1 ? false:true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */