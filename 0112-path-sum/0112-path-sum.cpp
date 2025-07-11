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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;

        if(root->left == nullptr && root->right == nullptr)
            return root->val == targetSum;

        int rem = targetSum-root->val;
        return hasPathSum(root->left , rem) || hasPathSum(root->right , rem);
    }
};