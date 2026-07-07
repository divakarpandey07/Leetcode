class Solution {
public:

    string toHex(int num) {
        
        if (num == 0) return "0";
        
        unsigned int x = num;

        string result;
        for(;x > 0; x/=16) {
            int n = x % 16;
            char c;
            if (n < 10) c = n + '0';
            else c = 'a' + n - 10 ;
            result = c + result;
        }
        return result;
    }
};