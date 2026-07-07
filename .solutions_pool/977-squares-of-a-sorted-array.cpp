class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        
        

        
        const int len = A.size();
        int low = 0, high = len- 1;
        int mid =0;
        while (low <= high) {
            mid = low + (high - low)/2;
            if (A[mid] >= 0 ) high = mid - 1;
            if (A[mid] < 0 ) low = mid + 1;
        }

        
        if (A[mid] > 0 && mid > 0 ) mid--;
        

        vector<int> result;
        low = mid; high = mid+1;
        while ( low >=0 && high < len ) {
            if ( abs(A[low]) < abs(A[high]) ) {
                result.push_back(A[low] * A[low]);
                low --;
            }else {
                result.push_back(A[high] * A[high]);
                high++;
            }
        }

        for (;low >= 0; low--) result.push_back(A[low] * A[low]);
        for (;high<len; high++) result.push_back(A[high] * A[high] );

        return result;
    }
};