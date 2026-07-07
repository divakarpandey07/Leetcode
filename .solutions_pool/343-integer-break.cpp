class Solution {
public:
    
    
    
    
    
    
    
    
    
    int integerBreak(int n) {
        if ( n == 2 ) return 1;
        if ( n == 3 ) return 2;
        int result = 1;
        while( n > 4 ) {
            result *= 3;
            n -= 3;
        }
        result *= n;
        return result;
    }
};

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1,1);
        for(int i=2;i<=n;i++){
            for(int j=1;j<=i/2;j++){
                dp[i] = max(dp[i],max(dp[j],j)*max(dp[i-j],i-j));
            }
        }
        return dp[n];
    }
};