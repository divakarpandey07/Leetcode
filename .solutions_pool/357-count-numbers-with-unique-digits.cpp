class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int result = 1;
        for (int i=0; i<n; i++) {
            result += ( 9 * nine_factor(i) );
        }
        return result;
    }

    int nine_factor(int n) {
        int result = 1;
        for (int i=0; i<n; i++) {
            result *= (9-i);
        }
        return result;
    }
};

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int result = 1;
        int nine_factor = 1;
        for (int i=0; i<n; i++) {
            result += ( 9 * nine_factor );
            nine_factor *= (9-i);
        }
        return result;
    }

};