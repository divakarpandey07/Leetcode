class Solution {
private:

    
    
    
    int findGCD_r(int a, int b) {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }
    
    int findGCD(int a, int b) {
        int t = 1;
        while(t != 0) {
            t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    bool isStrRepeatByLen(string& s, int len) {
        if (s.size() == len) return true;
        if (s.size() % len != 0 ) return false;
        for (int l=0; l<len; l++) {
            for (int i=1; i<s.size()/len; i++) {
                if (s[l] != s[i*len+l]) return false;
            }
        }
        return true;
    }

    bool strPrefixComp(string& s1, string &s2, int len){
        for(int i=0; i<len; i++) {
            if (s1[i] != s2[i]) return false;
        }
        return true;
    }
public:
    string gcdOfStrings(string s1, string s2) {

        int gcd = findGCD(s1.size(), s2.size());

        if (strPrefixComp(s1, s2, gcd) &&
            isStrRepeatByLen(s1, gcd)&&
            isStrRepeatByLen(s2, gcd) ){
            return s2.substr(0,gcd);
        }

        return "";
    }
};