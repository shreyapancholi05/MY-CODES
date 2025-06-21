class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        stack<int> s;
        for(auto it : asteroids){
            if(it > 0 || s.empty()){
                s.push(it);
            }
            else{
                while(!s.empty() && s.top() > 0 &&  s.top() < abs(it)){
                    s.pop();

                }
                
                if(!s.empty() && s.top() == abs(it)){
                    s.pop();
                }
                else if(s.empty() || s.top()<0){
                    s.push(it);
                }
            }
        }
        vector<int> result;
        while (!s.empty()) {
            result.push_back(s.top());
            s.pop();
        }
        reverse(result.begin(), result.end());
        return result;

    }
};