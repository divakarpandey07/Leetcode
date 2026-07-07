class Solution {
public:
    
    bool compareInterval(Interval& lhs, Interval& rhs) {
        return lhs.start < rhs.start;
    }
    
    bool overlapped(Interval& lhs, Interval& rhs) {
        return (compareInterval(lhs, rhs)) ?
                             lhs.end >= rhs.start:
                             rhs.end >= lhs.start;

    }
    
    Interval mergeTwoInterval(Interval& lhs, Interval& rhs) {
        Interval result;
        result.start = max(lhs.start, rhs.start);
        result.end = min(lhs.end, rhs.end);
        return result;
    }

    vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B) {
        int lenA = A.size();
        int lenB = B.size();

        vector<Interval> result;
        if (lenA <=0 || lenB<=0) return result; 

        int i=0, j=0;
        while ( i < lenA && j < lenB ) {
            if( overlapped(A[i], B[j]) ) {
                result.push_back(mergeTwoInterval(A[i], B[j]));
                
                
                int nexti = i;
                if ( j==lenB-1 || !overlapped(A[i], B[j+1]) ) nexti=i+1;
                if ( i==lenA-1 || !overlapped(A[i+1], B[j]) ) j++;
                i = nexti;
            }else{
                
                compareInterval(A[i], B[j]) ? i++ : j++;
            }
        }
        return result;
    }
};