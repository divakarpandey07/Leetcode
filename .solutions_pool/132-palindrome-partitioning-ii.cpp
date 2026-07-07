#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

bool isPalindrome(string &s, int start, int end);
void minCutHelper(string &s, int start, int steps, int& min );
int minCutHelper(string &s, int steps, int& minSteps );
int minCut_DP(string& s); 

int minCut(string s) {
    #define INT_MAX 2147483647
    if(s.size()<=1) return 0;

    int min = INT_MAX;
    
    
    

    
    

    return minCut_DP(s);
}

int minCut_DP(string& s) {
    
    vector<int>res(s.size(),0);
    
    bool mp[s.size()][s.size()];

    
    
    
    
    
    
    for (int i=s.size()-1;i>=0;i--){
        for (int j=i;j<s.size();j++){
            if ((s[i]==s[j]) && (j-i<2 || mp[i+1][j-1])){
                mp[i][j]=true;
            }else{
                mp[i][j]=false;
            }
        }
    }
    
    for (int i=0;i<s.size();i++){
        
        if (mp[0][i] == true){
            res[i]=0;
        }else{
            
            
            
            
            int ms = s.size();
            for (int j=0; j<i; j++){
                if (mp[j+1][i] && ms>res[j]+1 ) {
                    ms=res[j]+1;
                } 
            }
            res[i]=ms;
        }
    }
    return res[s.size()-1];
}

int minCutHelper(string &s, int steps, int& minSteps ) {

    
    if (minSteps <= steps) {
        return -2;
    }
    
    static map<string, int> cache;
    if ( cache.find(s)!=cache.end() ){
        if (s.size()>0)
            cout << s << ":" << cache[s] << endl;
        return cache[s];
    }
    if (s.size()==0) {
        if (minSteps > steps){
            minSteps = steps;
        }
        cache[s] = 0;
        return 0;
    }

    int min = INT_MAX;
    string subs;
    int m; 
    for( int i=s.size()-1; i>=0; i-- ) {
        
        if ( i < s.size()-1 && minSteps - steps <= 1) {
            break;
        }
        if ( isPalindrome(s, 0, i) ){
            
            
            
            subs = s.substr(i+1, s.size()-i-1);
            m = minCutHelper(subs, steps+1, minSteps) + 1;
            
            if (m < 0) continue;
            cache[subs] = m-1;
            if (min > m ){
                min = m;
            }
        }
    }
    return min;
}

void minCutHelper(string &s, int start, int steps, int& min ) {

    if (start == s.size()) {
        if (steps < min) {
            min = steps;
            return;
        }
    }

    
    for(int i=s.size()-1; i>=start; i--){
        
        if ( min > steps && isPalindrome(s, start, i)) {
            minCutHelper(s, i+1, steps+1, min );
        }
    }
}

bool isPalindrome(string &s, int start, int end)  {  

    while(start < end)  {  
        if(s[start] != s[end]) { 

            return false;  
        }
        start++; end--;  
    }  

    return true;  
}  

int main(int argc, char** argv)
{
    string s("aab");
    if ( argc > 1 ){
        s = argv[1];
    }

    cout << s << " : " << minCut(s) << endl;

}