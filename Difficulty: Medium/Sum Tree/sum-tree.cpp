/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution {
    pair<bool, int> isSum(Node* root){
        if(root == NULL){
            pair<bool , int> p = make_pair(true, 0);
            return p;
        }
        
        if(root->left == NULL && root -> right == NULL){
            pair<bool , int> p = make_pair(true, root->data);
            return p;
        }
        
        pair<bool , int> leftsum = isSum(root->left);
        pair<bool , int> rightsum = isSum(root->right);
        
        bool leftans = leftsum.first;
        bool rightans = rightsum.first;
        
        bool check = root->data == leftsum.second + rightsum.second;
        
        pair<bool , int> ans;
        if(leftans && rightans && check){
            ans.first = true;
            ans.second = root->data + leftsum.second + rightsum.second;
            
        }
        else{
            ans.first = false;
        }
        
        return ans;
    }
  public:
    bool isSumTree(Node* root) {
        // Your code here
        return isSum(root).first;
        
    }
};