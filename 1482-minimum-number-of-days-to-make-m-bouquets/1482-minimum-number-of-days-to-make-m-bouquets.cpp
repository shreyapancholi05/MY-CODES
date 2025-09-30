class Solution {
public:
    bool possible(vector<int>& bloomDay,int day, int m, int k){
        int n = bloomDay.size();
        int cnt = 0;
        int bouq = 0;
        for(int i=0; i<n; i++){
            if(bloomDay[i] <= day){
                cnt++;
            }
            else{
                bouq += (cnt/k);
                cnt = 0;
            }
        }
        bouq += cnt/k;
        return bouq >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = 1;
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        if(bloomDay.size() < m*1LL*k*1LL){
            return -1;
        }
        while(low <= high){
            int mid = low +(high -low)/2;

            if(possible(bloomDay, mid, m , k)){
                high = mid - 1;

            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};