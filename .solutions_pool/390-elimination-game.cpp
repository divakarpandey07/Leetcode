class Solution {
public:
    int lastRemaining(int n) {
        int start = 1, step = 1;
        while (n > 1) {
            start += step + (n-2)/2 * 2*step;
            n /= 2;
            step *= -2;
        }
        return start;
    }
};