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
    TreeNode*ans = NULL;
    void find(TreeNode* root, TreeNode* p, TreeNode* q){
     if(!root)return;
     if(root->val<=q->val && root->val>=p->val){
    ans = root;
      return;
    }  
    else if(root->val<q->val && root->val<p->val){
     find(root->right,p,q);
    }
    else find(root->left,p,q);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode*small = NULL;
    TreeNode*big = NULL;
    if(p->val < q->val){ 
    small = p;
    big = q;
    }
    else {
        small = q;
        big = p;
    }
    find(root,small,big);
    return ans;
}
};
