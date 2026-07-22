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
   bool a = true;
   int height(TreeNode*root){
      if(root==NULL)return 0;
    int lheight = height(root->left);
    int rheight = height(root->right);
    if(abs(lheight-rheight) > 1){a = false;
    return 0;}
    return 1+max(lheight,rheight);
    }
    bool isBalanced(TreeNode* root) {
        int dummy = height(root);
        return a;
    }
};
