class Solution {
    bool is_lower(char ch) {
        return ch >='a' && ch <='z';
    }
    bool is_upper(char ch) {
        return ch >='A' && ch <='Z';
    }
    bool is_alpha(char ch) {
        return is_lower(ch) || is_upper(ch);
    }
public:
    bool detectCapitalUse(string word) {
        bool all_upper = true, all_lower = true, first = is_upper(word[0]);
        for(int i=1; i<word.size(); i++) {
            if (is_lower(word[i])) all_upper = false;
            if (is_upper(word[i])) all_lower = false;
        }
        return all_lower || first && all_upper; 
    }
};