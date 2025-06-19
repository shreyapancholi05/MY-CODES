class Solution {
  public:
    void bitManipulation(int num, int i) {
        // your code here
        i--;
          
        int a1 = (num >> i) & 1;
        
        int a2 = num | (1<<i);
        
        int a3 = num & ~(1<<i);
        
        
        cout<<a1<<" "<<a2<<" "<<a3;
        
        
    }
};