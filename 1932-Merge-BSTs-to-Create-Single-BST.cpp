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
    void check(TreeNode* root,vector<int>& v){
        if(root->left)check(root->left,v);
        v.push_back(root->val);
        if(root->right)check(root->right,v);
    }

    TreeNode* canMerge(vector<TreeNode*>& trees) {
        unordered_map<int,int> map;
        unordered_map<int,TreeNode*> valToTreeMap;
        int sz = trees.size()-1;
        TreeNode* top;
        TreeNode* temp;
        TreeNode* head;
        queue<TreeNode*> q;
        for(auto x:trees){
            q.push(x);
            valToTreeMap[x->val] = x;
            while(!q.empty()){
                top = q.front();
                map[top->val]++;
                q.pop();
                if(top->left)q.push(top->left);
                if(top->right)q.push(top->right);
            }
        }
        for(auto x:trees){
            if(map[x->val] == 1)q.push(x);
        }
        if(q.size() != 1)return 0;
        head = q.front();
        cout<<head->val<<endl;
        while(!q.empty()){
            top = q.front();
            q.pop();
            if(map[top->val] > 1){
                sz--;
                if(!valToTreeMap.count(top->val))return 0;
                temp = valToTreeMap[top->val];
                if((temp->left && top->left) || (temp->right && top->right))return 0;
                if(temp->left)top->left = temp->left;
                if(temp->right)top->right = temp->right;
            }
            if(top->left)q.push(top->left);
            if(top->right)q.push(top->right);
        }
        if(sz)return 0;
        vector<int> v;
        check(head,v);
        for(int i = 1;i<v.size();i++){
            if(v[i-1] >= v[i])return 0;
        }
        return head;
    }
};