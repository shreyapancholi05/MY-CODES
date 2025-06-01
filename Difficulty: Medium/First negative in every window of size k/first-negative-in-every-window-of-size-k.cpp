//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        deque<int> dq;
        vector<int> ans;
        int n = arr.size();
        
        for(int i=0; i<k; i++){
            if(arr[i] < 0){
                dq.push_back(i);
            }
        }
        
        if(dq.size() > 0){
            ans.push_back(arr[dq.front()]);
        }
        else{
            ans.push_back(0);
        }
        
        for(int i=k; i<n; i++){
            if(!dq.empty() && i-dq.front() >=k){
                dq.pop_front();
            }
            if(arr[i] < 0){
                dq.push_back(i);
            }
            if(dq.size() > 0){
                ans.push_back(arr[dq.front()]);
            }
            else{
                ans.push_back(0);
                
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.firstNegInt(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends