/*Structure of the node of the binary tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    // Function to store the zig zag order traversal of tree in a list.
    vector<int> zigZagTraversal(Node* root) {
        // Code here
        vector<int> result;
        
        if(root == NULL)
        return result;
        
        queue<Node* > q;
        q.push(root);
        
        bool leftToright = true;
        while(!q.empty()){
            int size = q.size();
            
            vector<int> ans(size);
            for(int i=0; i<size; i++){
            Node* front = q.front();
            q.pop();
            int index = leftToright ? i : size - i - 1;
            ans[index] = front->data;
            
            if(front->left){
                q.push(front -> left);
            }
            
            if(front -> right){
                q.push(front -> right);
            }
            }
            
            leftToright = !leftToright;
            
            for(auto i : ans){
                result.push_back(i);
            }
        }
        return result;
        
    }
};