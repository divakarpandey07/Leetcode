class Solution {
public:
    bool isPowerOfFour(int num) {
        static int mask = 0b01010101010101010101010101010101;
        
        
        if (num<=0) return false;
        
        
        if ((num & num-1) != 0) return false;
        
        
        
        if ((num & mask) != 0) return true;
        return false;
    }
};