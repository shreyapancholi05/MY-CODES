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
    unordered_map<int , int> freq;
    int sum(TreeNode *root){
        if(root == nullptr) return 0;
        int left = sum(root->left);
        int right = sum(root->right);
        int total = left + right + root->val;
        freq[total]++;
        return total;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        sum(root);
        int maxFreq = 0;
        for(auto it : freq)
            maxFreq = max(maxFreq , it.second);
        
        for(auto it : freq){
            /*if(maxFreq < it.second){
                ans.clear();
                ans.push_back(it.second);
                maxFreq = 0;
            }
            */
            if(maxFreq == it.second){
                ans.push_back(it.first);
            }
        }
    return ans;


    }
};