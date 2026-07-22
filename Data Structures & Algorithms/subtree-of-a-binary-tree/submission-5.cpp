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
    void dfs(TreeNode* root1, TreeNode* root2,bool &ans){
        if (!root1 && !root2) return;
        if (!root1 || !root2) {
            ans = false;
            return;
        }
        if (root1->val != root2->val) {
            ans = false;
            return;
        }
        dfs(root1->left, root2->left,ans);
        dfs(root1->right, root2->right,ans);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
      bool i = true;
        dfs(p, q,i);
        return i;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
     if(!root)return false;
     if(root->val == subRoot->val && isSameTree(root,subRoot))return true;
     else return isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot);
    }
};
