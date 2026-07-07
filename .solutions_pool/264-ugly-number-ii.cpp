class Solution {
public:

    int min(int a, int b) {
        return a < b ? a:b;
    }
    
    int min(int a, int b, int c) {
        return min( min(a, b),  c);
    }

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    int nthUglyNumber01(int n) {
            
        int i=0, j=0, k=0;
        vector<int> v(1,1);
        
        while(v.size() < n){
            int next = min(v[i]*2, v[j]*3, v[k]*5);
            if (next == v[i]*2) i++;
            if (next == v[j]*3) j++;
            if (next == v[k]*5) k++;
            v.push_back(next);
        }
        return v.back();
    }
    
    
    
    int nthUglyNumber02(int n) {
            
        static int i=0, j=0, k=0;
        static vector<int> v(1,1);
    
        if (v.size()>=n) return v[n-1];
        
        while(v.size() < n){
            int next = min(v[i]*2, v[j]*3, v[k]*5);
            if (next == v[i]*2) i++;
            if (next == v[j]*3) j++;
            if (next == v[k]*5) k++;
            v.push_back(next);
        }
        return v.back();
    }
    
    int nthUglyNumber(int n) {
        return nthUglyNumber02(n); 
        return nthUglyNumber01(n); 
    }
};