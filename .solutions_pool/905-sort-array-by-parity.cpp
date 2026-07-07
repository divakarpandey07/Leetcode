class Solution {
public:
    bool isEven(int& x) {
        return x % 2 == 0;
    }
    vector<int> sortArrayByParity(vector<int>& A) {
        
        
        int l=0, r=A.size()-1;
        while ( l < r ) {
            if ( !isEven(A[l]) && isEven(A[r]) ) swap(A[l], A[r]);
            if ( isEven(A[l]) ) l++;
            if ( !isEven(A[r]) ) r--;
        }
        return A;
    }
};