class Solution {
public:
    int longestPalindrome(string s) {
        
        int hashtable[128];
        memset(hashtable, 0, sizeof(hashtable));
        
        for(char ch : s) {
            hashtable[ch]++;
        }
        int result = 0;
        bool hasOdd = false;
        for (int n : hashtable) {
            if ( n%2 == 0 ) {
                result += n;
            } else {
                result += n -1;
                hasOdd = true;
            }
        }
        
        return hasOdd ? result + 1 : result;
    }
};