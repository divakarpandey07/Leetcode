#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool isPalindrome(string& s, int begin, int end) {
    for (; begin<end; begin++, end-- ) {
        if ( s[begin] != s[end] ) {
            return false;
        }
    }
    return true;
}

string shortestPalindrome_bf(string& s) {
    int len = s.size();
    int i;
    for (i=len-1; i>=0; i--) {
        if (isPalindrome(s, 0, i)) { 
            i++;
            break;
        }
    }
    string t = s.substr(i, len-i);
    reverse(t.begin(), t.end());
    return t+s;
}

string shortestPalindrome_dp(string& s) {
    int len = s.size();
    if (len <=1 ) return s;

    
    vector< vector<bool> > dp(len, vector<bool>(len, false));
    for (int i=len-1; i>=0; i--){
        for(int j=i; j<len; j++){
            if (i==j || ((j-i==1 || dp[i+1][j-1]) && s[i]==s[j]) ) {
                dp[i][j] = true;
            }
        } 
    }  

    
    
    
    int pos = 0;
    for (int i=1; i<len; i++)  {
        if (dp[0][i]) {
            pos = i+1;
        } 
    }
    string t = s.substr(pos, len - pos);
    reverse(t.begin(), t.end());
    return t+s;
    
}

string shortestPalindrome_kmp(string& s) {  
    int len = s.size();
    if(len <= 1) return s;
    
    string pattern = s + '\0' + string(s.rbegin(), s.rend());  

    
    vector<int> prefix( pattern.size() );  
    prefix[0] = 0;
    for(int i = 1; i < prefix.size(); i++) {  
        int j = prefix[i-1];  
        while( j > 0 && pattern[i] != pattern[j] ) {
            j = prefix[j-1];  
        }
        if ( pattern[i] == pattern[j] ) {
            j++;  
        }
        prefix[i] = j;  
    }  

#ifdef _DEBUG
    cout << endl;
    for(int i=0; i<pattern.size(); i++){
        
        cout << (pattern[i] ? pattern[i] : '#') << "  ";
    }
    cout << endl;
    for(int i=0; i<prefix.size(); i++) {
        cout << prefix[i] << "  ";
    }
    cout << endl;
    cout << "-->" << s.substr(0, prefix.back()) << " " << s.substr(prefix.back()) << endl;
#endif

    int pos = s.size() - prefix.back();  
    return string(s.rbegin(), s.rbegin() + pos) + s;  
}  

string shortestPalindrome(string s) {
    return shortestPalindrome_kmp(s); 
    return shortestPalindrome_dp(s); 
    return shortestPalindrome_bf(s); 
}
#define TEST(s)  cout << s << " : " << shortestPalindrome(s) << endl

int main(int argc, char**argv)
{
    string s = "aabba";
    if (argc>1){
        s = argv[1];
    }
    TEST(s);
    TEST("a");
    TEST("ab");
    TEST("aba");
    TEST("abab");
    TEST("aabb");
    TEST("aacecaaa");
    TEST("abcd");
    TEST("aaabcb");
    return 0;
}