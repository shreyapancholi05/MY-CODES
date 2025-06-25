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
    int sum = 0;
    int maxdepth = -1;
    void dfs(TreeNode* root , int currDepth){
        if(root == NULL) return;
        if(currDepth > maxdepth){
            maxdepth = currDepth, sum = root->val;
        }
        else if(currDepth == maxdepth){
            sum += root->val;
        }

        dfs(root->left , currDepth+1);
        dfs(root->right, currDepth+1);
    }
public:
    
    
    int deepestLeavesSum(TreeNode* root) {
        dfs(root,0);
        return sum;
    }
};