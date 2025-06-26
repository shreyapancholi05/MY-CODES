/* A binary tree node structure

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
 */

class Solution {
    pair<bool,int> balance(Node* root){
        if(root == NULL){
            pair<bool , int> p = make_pair(true , 0);
            return p;
        }
        
        pair<int, int> left = balance(root->left);
        pair<int, int> right = balance(root->right);
        
        bool leftans = left.first;
        bool rightans = right.first;
        
        bool diff = abs(left.second - right.second) <= 1;
        
        pair<bool , int> ans;
        ans.second = max(left.second , right.second) + 1;
        
        if(leftans && rightans && diff){
            ans.first = true;
        }
        else{
            ans.first = false;
        }
        
        return ans;
        
    }
  public:
    bool isBalanced(Node* root) {
        // Code here
        
        return balance(root).first;
        
    }
};