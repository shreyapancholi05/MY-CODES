// Class that contains the logic to build the binary tree
/*
Definition of the Node class
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
  public:
    int findPosition(vector<int> inorder, int element, int n){
        for(int i=0; i<n; i++){
            if(inorder[i] == element){
                return i;
            }
        }
        return -1;
    }
    Node* solve(vector<int> &inorder, vector<int> &preorder, int &index,
                int inorderstart, int inorderend, int n){
        
        if(index >= n || inorderstart > inorderend){
            return NULL;
        }
        
        int element = preorder[index++];
        Node* root = new Node(element);
        int position = findPosition(inorder, element, n);
        
        root->left = solve(inorder, preorder, index, inorderstart, position-1, n);
        root->right = solve(inorder, preorder, index, position+1, inorderend, n);
        
        return root;
   }
    // Function to build the tree from given inorder and preorder traversals
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // code here
        int n = preorder.size();
        int preOrderIndex = 0;
        Node* ans = solve(inorder, preorder, preOrderIndex, 0, n-1, n);
        return ans;
    }
};