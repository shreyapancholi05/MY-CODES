/*
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
class Solution {
  public:
    vector<int> reverseLevelOrder(Node *root) {
        // code here
        queue<Node*> q;
        stack<Node*> s;
        q.push(root);
        
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            
            s.push(temp);
            if(temp->right) q.push(temp->right);
            
            if(temp->left) q.push(temp->left);
            
            
        }
        
        while(!s.empty()){
            Node* curr = s.top();
            cout<< curr->data << " ";
            s.pop();
        }
    }
};