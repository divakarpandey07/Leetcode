class Solution {
public:

    int integerReplacement_recursion(int n) {
        if ( n <= 1) return 0; 
        if ( n == INT_MAX ) return 32; 
        if ( n % 2 == 0 ) return integerReplacement(n/2) + 1;
        return min( integerReplacement(n+1), integerReplacement(n-1) ) + 1;
    }
    
    int integerReplacement_recursionWithCache(int n) {
        static unordered_map<int, int> cache;
        
        if (cache.find(n) != cache.end()) return cache[n];
        
        int result;
        if ( n <= 1) return 0; 
        if ( n == INT_MAX ) return 32; 
        if ( n % 2 == 0 ) result = integerReplacement(n/2) + 1;
        else result = min( integerReplacement(n+1), integerReplacement(n-1) ) + 1;
        
        
        cache[n] = result;
        return result;
    }
    
    int integerReplacement_simple(int n){
        int ans = 0;
        size_t m = n;
        while (1 != m) {
            if (1 == (m & 1)) {
                if (m==3) --m; 
                else m = (m&0b11^0b01) ? m + 1 : m - 1;
            }
            else m >>= 1;
            ++ans;
        }
    return ans;
    }

    int integerReplacement(int n) {
        return integerReplacement_recursionWithCache(n);
        return integerReplacement_simple(n);
    }
};