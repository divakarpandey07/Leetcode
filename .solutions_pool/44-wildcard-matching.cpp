#include <iostream>
#include <string>
using namespace std;

bool isMatch(const char *s, const char *p) {

    const char *last_s = NULL; 
    const char *last_p = NULL;
    while( *s != '\0' ){
        if (*p=='*'){
            
            p++;
            
            if (*p=='\0') return true;
            
            last_s = s;
            last_p = p;
        }else if (*p=='?' || *s == *p){
            s++; p++;
        }else if (last_s != NULL){ 
            
            
            p = last_p;
            s = ++last_s; 
        }else{
            
            
            
            return false;
        }
    }
    
    while (*p == '*') p++;
    return *p == '\0';
}

int main(int argc, char** argv)
{
    const char *s = "aab";
    const char *p = "a*a*b";
    cout << s << ", " << p << " : " << isMatch(s, p) << endl;

    s = "abbb";
    p = "a*b";
    cout << s << ", " << p << " : " << isMatch(s, p) << endl;

    s = "abb";
    p = "a*bb";
    cout << s << ", " << p << " : " << isMatch(s, p) << endl;

    s = "abddbbb";
    p = "a*d*b";
    cout << s << ", " << p << " : " << isMatch(s, p) << endl;

    s = "abdb";
    p = "a**";
    cout << s << ", " << p << " : " << isMatch(s, p) << endl;

    s = "a";
    p = "a**";
    cout << s << ", " << p << " : " << isMatch(s, p) << endl;

    
    s = "*aa"; 
    p = "*a";
    cout << s << ", " << p << " : " << isMatch(s, p) << endl;

    if (argc>2){
        s = argv[1];
        p = argv[2];
        cout << s << ", " << p << " : " << isMatch(s, p) << endl;
    }
    return 0;
}