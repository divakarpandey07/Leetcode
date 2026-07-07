class Solution {
public:
    
    int maxTurbulenceSize_01(vector<int>& A) {
        
        if (A.size() <= 1) return A.size();
        
        
        enum Status {
            up,
            down,
            none
        } s = none;
        
        int maxlen = 1;
        int len = 1;
        
        for (int i=1; i< A.size(); i++) {
            
            
            if ( A[i] == A[i-1] ) { 
                s = none;
                continue;
            }
            
            
            if ( s == none ) {
                s = A[i] > A[i-1] ? up : down;
                len = 2;
                continue;
            }
            
            
            
            if ( s == up ) {
                if ( A[i] < A[i-1] ) {
                    len++;
                    s = down;
                }else{
                    len=2;
                }
            }else{
                if ( A[i] > A[i-1] ) {
                    len++;
                    s = up;
                }else{
                    len=2;
                }
            }
            
            maxlen = len > maxlen ? len : maxlen;
            
        }
        return maxlen;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    int maxTurbulenceSize_02(vector<int>& A) {
        
        if (A.size() <= 1) return A.size();
        
        int up = 1;
        int down = 1;
        int maxlen = 1;
        
        for (int k=1; k<A.size(); k++) {     
            
            int u = up, d = down;
            
            up = (A[k] > A[k-1]) ? d + 1 : 1;
            down =  (A[k] < A[k-1]) ? u + 1 : 1;

            int len = down > up ? down : up;
            maxlen = len > maxlen ? len : maxlen;
        }
        return maxlen;
    }
    
    int maxTurbulenceSize(vector<int>& A) {
        return maxTurbulenceSize_02(A);
        return maxTurbulenceSize_01(A);
    }
};