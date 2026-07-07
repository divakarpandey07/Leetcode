class Solution {
public:
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    int sum1toN(int n) {
        return n * (n+1) / 2;
    }

    int numberOfArithmeticSlices(vector<int>& A) {
        int result = 0;
        int len = 0; 
        for (int i=2; i<A.size(); i++) {
            if (A[i] - A[i-1] == A[i-1] - A[i-2]) {
                len++;
            }else{
                result += sum1toN(len);
                len=0;
            }
        }
        return len==0 ? result : result + sum1toN(len);
    }
};