class Solution {
public:
    int minInsertions(string s) {
        vector<char> stack;
        
        int cnt = 0;
        int len = s.size();
        for (int i=0; i<len; i++) {
            
            if ( s[i] == '(' ) {
                stack.push_back( s[i] );
                continue;
            }
            
            if (stack.size() > 0)  {
                stack.pop_back();
            } else {
                cnt++; 
            }
            
            
            if ( i < len -1 && s[i+1] == ')' ) {
                i++;
            }else{
                cnt++; 
            }
         
        }
        
        
        return cnt + stack.size()*2;
    }
};