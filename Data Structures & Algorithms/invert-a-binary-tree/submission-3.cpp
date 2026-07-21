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
    void inorder(TreeNode*node){
      //base condition for the recursion to stop
      if(node==NULL)return;
      TreeNode* temp = node->right;
      node->right = node->left;
      node->left = temp;
      inorder(node->left);
      inorder(node->right);
    }
    TreeNode* invertTree(TreeNode* root) {
       inorder(root);
        return root;
    }
};
