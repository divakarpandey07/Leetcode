class Solution {
public:
    string strWithout3a3b(int A, int B) {

        string result;
        while (true){

            
            if (A == B) {
                for ( int i=0; i<A; i++ ) {
                    result += "ab";
                }
                break;
            }

            
            if (A+B <3) {
                while  ( A-- > 0 ) result += 'a';
                while  ( B-- > 0 ) result += 'b';
                break;
            }

            

            
            
            if ( A > B ) {
                result += "aab";
                A -= 2;
                B--;
                continue;
            }

            
            
            if (B > A ){
                result += "bba";
                B-=2;
                A--;
                continue;
            }

        }

        return result;
    }
};