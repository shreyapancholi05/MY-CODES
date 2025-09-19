// User function Template for C++
class Solution {
  public:
    bool armstrongNumber(int n) {
        // code here
        int og = n;
        int sum = 0;
            while(n > 0){
            int digit = n%10;
            sum += pow(digit, 3);
            
            n = n/10;
        
        }
        if(sum == og){
            return true;
        }
    
        return false;
    }
};