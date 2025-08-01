/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    void createMapp(vector<int> &inorder, map<int, int> &nodetoIndex, int n){
        for(int i=0; i<n; i++){
            nodetoIndex[inorder[i]] = i;
        }
    }
    Node* solve(vector<int> &inorder, vector<int> &postorder, int &index,
        int inorderstart, int inorderend, int n, map<int, int> &nodetoIndex){
        
        if(index < 0 || inorderstart > inorderend){
            return NULL;
        }
        
        int element = postorder[index--];
        Node* root = new Node(element);
        // int position = findPosition(inorder, element, n);
        /* directly finding position from map in O(1) */
        int position = nodetoIndex[element];
        
        root->right = solve(inorder, postorder, index, position+1, inorderend, n,nodetoIndex);
        root->left = solve(inorder, postorder, index, inorderstart, position-1, n, nodetoIndex);
        
        return root;
   }
    // Function to return a tree created from postorder and inoreder traversals.
    Node* buildTree(vector<int> inorder, vector<int> postorder) {
        // code here
        int n = postorder.size();
        int postOrderIndex = n-1;
        map<int, int> nodetoIndex;
        createMapp(inorder, nodetoIndex, n);
        Node* ans = solve(inorder, postorder, postOrderIndex, 0, n-1, n, nodetoIndex);
        return ans;
        
    }
};