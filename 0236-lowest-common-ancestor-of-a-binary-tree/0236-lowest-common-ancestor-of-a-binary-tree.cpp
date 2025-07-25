/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        
        if(!root || root == p || root == q){
            return root;
        }
        TreeNode* left = dfs(root->left,p,q);
        TreeNode* right = dfs(root->right,p,q);
        if(left && right) return root;
        if(left)
             return left;
        else
            return right;
        
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root,p,q);
     }
};