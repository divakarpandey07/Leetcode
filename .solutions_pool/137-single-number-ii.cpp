class Solution {
public:
    Solution(){
        srand(time(0));
    }
    
    
    int singleNumber(int A[], int n) {
        if (rand()%2){
            return singleNumber_1(A, n);
        }
        return singleNumber_2(A, n);
    }

    
    int singleNumber_1(int A[], int n) {
        int count[32] = {0};
        int result = 0;
        for (int i = 0; i < 32; i++) {
            for (int j = 0; j < n; j++) {
                if ((A[j] >> i) & 1) {
                    count[i]++;
                }
            }
            result |= ((count[i] % 3) << i);
        }
        return result;
    }

    
    int singleNumber_2(int A[], int n) {
        int ones = 0, twos = 0, threes = 0;
        for (int i = 0; i < n; i++) {
            
            twos |= ones & A[i]; 
            
            ones ^= A[i];
            
            threes = ones & twos;
            
            ones &= ~threes;
            twos &= ~threes;
        }
        return ones;
    }

};