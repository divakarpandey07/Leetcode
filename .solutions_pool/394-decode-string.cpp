class Solution {
public:
    string decodeString(string s) {
        if (!isValid(s)) return "";
        
        stack<string> _stack;
        stack<int> _nstack;
        
        string result;
        string tmp;
        int n=0;
        for (int i=0; i<s.size(); i++) {
            
            if ( isNum(s[i]) ) {
                n = 0;
                for(; isNum(s[i]); i++ ) {
                   n = n*10 + s[i] - '0'; 
                }
            }
            
            if (s[i] == '[') {
                tmp="";
                _stack.push(tmp);
                _nstack.push(n);
            } else if (s[i] == ']') {
                n = _nstack.top(); 
                tmp="";
                for (; n>0; n--) {
                    tmp += _stack.top();
                }
                _stack.pop();
                _nstack.pop();
                if ( ! _stack.empty() ) {
                    _stack.top() += tmp;
                }else {
                    result += tmp;
                }
            } else {
                if ( ! _stack.empty() ) {
                    _stack.top() += s[i];
                } else {
                    result += s[i];
                }
                
            }
        }
        
        return result;
    }
    
private:

    
    
    
    bool isValid(string& s) {
        stack<char> _stack;
        for (int i=0; i<s.size(); i++) {
            if ( isNum(s[i]) ) {
                for(; isNum(s[i]); i++);
                if (s[i] != '[') {
                    return false;
                } 
                _stack.push('[');
                continue;
            } else if (s[i] == ']' ) {
                if ( _stack.top() != '[' ) return false;
                _stack.pop();
            }
        }
        
        return (_stack.size() == 0);
    }
    
    bool isNum(char ch) {
        return (ch>='0' && ch<='9');
    }
};