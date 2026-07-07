#include <string.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string findPalindrome(string s, int left, int right)
{
    int n = s.size();
    int l = left;
    int r = right;
    while (left>=0 && right<=n-1 && s[left] == s[right]) {
        left--;
        right++;
    }
    return s.substr(left+1, right-left-1);
}

string longestPalindrome_recursive_way(string s) {
    int n = s.size();
    if (n<=1) return s;

    string longest;
    
    string str;
    for (int i=0; i<n-1; i++) {
        str = findPalindrome(s, i, i);
        if (str.size() > longest.size()){
            longest = str;
        } 
        str = findPalindrome(s, i, i+1);
        if (str.size() > longest.size()){
            longest = str;
        } 
    }

    return longest; 
}

void findPalindrome(string s, int left, int right, int& start, int& len)
{
    int n = s.size();
    int l = left;
    int r = right;
    while (left>=0 && right<=n-1 && s[left] == s[right]) {
        left--;
        right++;
    }
    if (right-left-1 > len){
        len = right-left-1;
        start = left+1;
    }
}

string longestPalindrome_recursive_way2(string s) {
    int n = s.size();
    if (n<=1) return s;

    int start=0, len=0; 
    string longest;

    string str;
    for (int i=0; i<n-1; i++) {
        findPalindrome(s, i, i, start, len);
        findPalindrome(s, i, i+1, start, len);
    }

    return s.substr(start, len);
}

string longestPalindrome_dp_way(string s) {

    string longest;

    int n = s.size();
    if (n<=1) return s;
    
    

    
    

    
    vector< vector<bool> > matrix (n, vector<bool>(n));

    
    
    
    for (int i=n-1; i>=0; i--){
        for (int j=i; j<n; j++){
            
            
            
            
            if ( i==j || (s[i]==s[j] && (j-i<2 || matrix[i+1][j-1]) ) )  {
                matrix[i][j] = true;
                if (longest.size() < j-i+1){
                    longest = s.substr(i, j-i+1);
                }
            }
        }
    }

    return longest;
}

string longestPalindrome_dp_opt_way(string s) {

    int n = s.size();
    if (n<=1) return s;

    
    
    

    
    
    bool **matrix  = (bool**)malloc(n*sizeof(bool*));
    int start=0, len=0;
    
    
    
    for (int i=0; i<n; i++){
        matrix[i] = (bool*)malloc((i+1)*sizeof(bool));
        memset(matrix[i], false, (i+1)*sizeof(bool));
        matrix[i][i]=true;
        for (int j=0; j<=i; j++){
            
            
            
            
            if ( i==j || (s[j]==s[i] && (i-j<2 || matrix[i-1][j+1]) ) )  {
                matrix[i][j] = true;
                if (len < i-j+1){
                    start = j;
                    len = i-j+1;
                }
            }
        }
    }

    for (int i=0; i<n; i++) { 
        free (matrix[i]);
    }
    free(matrix);

    return s.substr(start, len);
}

string longestPalindrome(string s) {
    return longestPalindrome_dp_way(s);
    return longestPalindrome_dp_opt_way(s);
    return longestPalindrome_recursive_way2(s);
    return longestPalindrome_recursive_way(s);
}

int main(int argc, char**argv)
{
    string s = "abacdfgdcaba";
    if (argc > 1){
        s = argv[1];
    }
    cout <<  s << " : " << longestPalindrome(s) << endl;

    s = "321012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210123210012321001232100123210123";
    cout <<  s << " : " << longestPalindrome(s) << endl;
 
    
    s = "iptmykvjanwiihepqhzupneckpzomgvzmyoybzfynybpfybngttozprjbupciuinpzryritfmyxyppxigitnemanreexcpwscvcwddnfjswgprabdggbgcillisyoskdodzlpbltefiz";
    cout <<  s << " : " << longestPalindrome(s) << endl;

    return 0;
}