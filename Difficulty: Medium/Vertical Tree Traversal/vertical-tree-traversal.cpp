/*
// Tree Node
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
  public:
    vector<vector<int>> verticalOrder(Node *root) {
        // Your code here
        map<int, map<int , vector<int>>> nodes;
        queue<pair<Node*, pair<int, int>>> q;
        vector<vector<int>> ans;
        
        if(root == NULL)
            return ans;
        
        q.push(make_pair(root, make_pair(0, 0)));
        
        while(!q.empty()){
            pair<Node* , pair<int, int>> temp = q.front();
            q.pop();
            Node* frontNode = temp.first;
            int hd = temp.second.first;
            int level = temp.second.second;
            
            nodes[hd][level].push_back(frontNode->data);
            
            if(frontNode->left){
                q.push(make_pair(frontNode->left, make_pair(hd-1, level+1)));
            }
            
            if(frontNode->right){
                q.push(make_pair(frontNode->right, make_pair(hd+1, level+1)));
            }
        }
        
        for(auto i : nodes){
            vector<int> fin;
            for(auto j : i.second){
                for(auto k : j.second){
                    fin.push_back(k);
                }
            }
            ans.push_back(fin);
        }
        
        return ans;
    }
    
};