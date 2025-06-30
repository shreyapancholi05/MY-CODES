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
 map<TreeNode* , int> memo;
    int rob(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        if(memo.find(root) != memo.end())
            return memo[root];
        int canrob = root->val;
        if(root -> left){
            canrob += rob(root -> left -> left) + rob(root->left->right);
        }
        if(root -> right)
            canrob += rob(root->right->left) + rob(root->right->right);
        int cannotrob = rob(root->left) + rob(root->right);
        return memo[root] = max(canrob, cannotrob);
    }
};