class Solution {
public:
    NestedInteger deserialize(string s) {
        if (s.size()==0) return NestedInteger();
        int pos = 0;
        if (s[pos]!='[') return atoni(s, pos);
        
        return helper(s, ++pos);
    }
private:
    NestedInteger helper(string& s, int& pos) {
       
        NestedInteger ni;
        
        while ( s[pos] != ']' && pos < s.size() ) {

            if (s[pos]=='-' || isnum(s[pos])){
                ni.add(atoni(s, pos));
            }else if (s[pos] == '[') {
                pos++;
                ni.add(helper(s, pos));
            }else {
                pos++;
            }
        }
        pos++;
        return ni;
    }
    NestedInteger atoni(string& s, int& pos) {
        int sign = 1;
        int num = 0;
        if (s[pos]=='-') {
            sign = -1;
            pos++;
        }
        for (; pos < s.size(); pos++) {
            if (isnum(s[pos])) {
                num = num * 10 + s[pos] - '0';
            }else{
                break;
            }
        }
        return NestedInteger(sign * num);
    }
    bool isnum(char& c) {
        return (c >='0' && c <='9');
    }
};