#include <cmath>
using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        
        
        
        
        
        
        
        
        
        
        long digits_cnt = 0;
        long digits_cnt_prev = 0;
        int base = 0;
        for ( ; digits_cnt < n; base++) {
            digits_cnt_prev = digits_cnt;
            digits_cnt = digits_cnt +  9 * pow(10 , base) * ( base + 1 );
        }
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        int target = pow(10, base-1) + (n - digits_cnt_prev) / base - 1;
        int left = n - digits_cnt_prev - (n - digits_cnt_prev) / base * base;
        
        
        
        
        if ( left == 0 ) return (target) % 10;
        
        
        target++;
        return int( target / pow(10, base - left) ) % 10;
    }
};