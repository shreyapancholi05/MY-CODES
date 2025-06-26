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
    /*int ans = INT_MIN;
    int dfs(TreeNode* root){
        if(!root) return 0;
        int leftsum = dfs(root->left);
        int rightsum = dfs(root->right);
        ans = max({
            ans, root->val + leftsum + rightsum, root->val+leftsum, root->val+rightsum, root->val});
        return max({root->val + leftsum , root->val + rightsum, root->val, 0});
    }*/
    int ans = INT_MIN;
    int dfs(TreeNode* root){
        if(!root) return 0;
        int leftsum = max(0, dfs(root->left));
        int rightsum = max(0, dfs(root->right));
        ans = max(ans, root->val + leftsum + rightsum);
        return root->val + max(leftsum , rightsum);
    }
public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};