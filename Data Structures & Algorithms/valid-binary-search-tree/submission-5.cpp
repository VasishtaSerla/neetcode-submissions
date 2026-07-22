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
   bool ans = true;
   void dfs(TreeNode*root,int min,int max){
    if(!root)return;
    if(root->val>=max || root->val<=min){
        ans = false;
        return;
    }
    dfs(root->left,min,root->val);
    dfs(root->right,root->val,max);
    }

    bool isValidBST(TreeNode* root) {
        int min = -1001,max = 1001;
        dfs(root,min,max);
        return ans;
    }
};
