class Solution {
      using pii = pair<int , int>;
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
      priority_queue<pii, vector<pii>, greater<pii>> pq;
      for(int i=0; i<points.size(); i++){
        int x = points[i][0];
        int y = points[i][1];
        int dist = (x * x + y * y);
        pq.push({dist, i});
      }
      vector<vector<int>>ans;
      while(k--){
        pii p = pq.top();
        pq.pop();
        int idx = p.second;
        ans.push_back(points[idx]);
      }
      return ans;
    }
};