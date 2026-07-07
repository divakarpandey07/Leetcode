class Solution {
public:
    bool isEven(int &x) {
        return x % 2 == 0;
    }
    vector<int> sortArrayByParityII(vector<int>& A) {
        
        
        
        
        int even = 0;
        int odd = 1;
        while(even < A.size() && odd < A.size() ) {
            if ( !isEven(A[even]) && isEven(A[odd]) ) swap( A[even], A[odd] );
            if ( isEven(A[even]) ) even += 2;
            if ( !isEven(A[odd]) ) odd += 2;
        }
        return A;
    }
};