class Solution {
  public:
    // Function to delete middle element of a stack.
    void solve(stack<int> &s, int count , int size){
        //base case
        if(count == size/2){
            s.pop();
            return;
        }
        
        int num = s.top();
        s.pop();
        //recursion
        solve(s, count+1, size);
        
        s.push(num);
    }
    void deleteMid(stack<int>& s) {
        // code here..
        int count = 0;
        int size = s.size();
        solve(s, count , size);
    }
};