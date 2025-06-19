class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        set<int> primes = {2,3,5,7,11,13,17,19};
        int count = 0;
        for(int i=left; i<=right; i++){
            int result = __builtin_popcount(i);

            if(primes.count(result)){
                count++;
            }



        }
        return count;
    }
};