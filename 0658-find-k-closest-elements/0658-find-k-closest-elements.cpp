class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>> pq;
        for(int i : arr){
            int diff = abs(i-x);
            pq.push({diff , i});

            if(pq.size() > k){
                pq.pop();
            }

        
        }
        vector<int> result;
        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();

        }
        sort(result.begin() , result.end());
        return result;




        

    }
};