class Solution {
    public:
        int trailingZeroes(int n) {
            int result = 0;
            
            for(long long i=5; n/i>0 && i <= INT_MAX; i*=5){
                result += (n/i);
            }
            return result;
        }

        
        int trailingZeroes(int n) {
            int sum=0;
            int tmp=0;
            while(n/5>0)
            {
                tmp=n/5;
                sum+=tmp;
                n=tmp;
            }
            return sum;
        }
};