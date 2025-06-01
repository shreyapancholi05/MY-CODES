// using queue
class Solution {
  public:
    queue<int> rearrangeQueue(queue<int> q) {
        // code here
        queue<int> qu;
        
        int n = q.size();
        for(int i=0 ; i<n/2 ; i++){
            qu.push(q.front());
            q.pop();
        }
        
        while(!qu.empty()){
            int val = qu.front();
            qu.pop();
            q.push(val);
            val = q.front();
            q.pop();
            q.push(val);
        }
        return q;
    }
};

// using stack
class Solution {
  public:
    queue<int> rearrangeQueue(queue<int> q) {
        stack<int> s;
        
        int n = q.size();
        for(int i=0; i<n/2; i++){
            s.push(q.front());
            q.pop();
            
        }
        while(!s.empty()){
        int val = s.top();
        s.pop();
        q.push(val);
        }
        
        for(int i=0 ; i< n/2 ; i++){
            q.push(q.front());
            q.pop();
            
        }
        
        for(int i=0; i<n/2; i++){
            s.push(q.front());
            q.pop();
        }
        
        while(!s.empty()){
            int val = s.top();
            s.pop();
            q.push(val);
            val = q.front();
            q.pop();
            q.push(val);
        }
        return q;
    }
};
