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
    vector<TreeNode*> pp, qq, temp;
    void dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return;
        temp.push_back(root);
        if(root == p) pp = temp;
        if(root == q) qq = temp;
        dfs(root->left,p, q);
        dfs(root->right,p ,q);
        temp.pop_back();
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p ,q);
        TreeNode* ans;
        for(int i=0 ; i<min(qq.size(),pp.size()); i++){
            if(pp[i] == qq[i])
                ans = pp[i];
            else
                break;
        }
        return ans;
    }
};