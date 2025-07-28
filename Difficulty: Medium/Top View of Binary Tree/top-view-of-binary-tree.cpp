/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        // code here
        map<int, int> mp;
        queue<pair<Node*, int>> q;
        
        vector<int> ans;
        
        if(root == NULL){
            return ans;
        }
        
        q.push(make_pair(root, 0));
        while(!q.empty()){
            pair<Node* , int> temp = q.front();
            q.pop();
            Node* newnode = temp.first;
            int hd = temp.second;
            
            if(mp.find(hd) == mp.end()){
                mp[hd] = newnode->data;
            }
            
            if(newnode->left){
                q.push(make_pair(newnode->left, hd-1));
            }
            
             if(newnode->right){
                q.push(make_pair(newnode->right, hd+1));
            }
        }
        for(auto i : mp){
            ans.push_back(i.second);
        }
        
        return ans;
    }
};