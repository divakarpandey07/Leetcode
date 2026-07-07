#include <string.h>
#include <iostream>
#include <string>
using namespace std;

#define INT_MAX      2147483647

string minWindow(string s, string t) {
    string win;
    if (s.size()<=0 || t.size()<=0 || t.size() > s.size()) return win;
        
    const int MAX_CHARS = 256;
    int window[MAX_CHARS], dict[MAX_CHARS];

    const int NOT_EXISTED   = -1;
    const int NOT_FOUND     =  0;
    memset(dict, NOT_EXISTED, sizeof(dict));
    memset(window, NOT_EXISTED, sizeof(window));

    
    for(int i=0; i<t.size(); i++) {
        dict[t[i]]==NOT_EXISTED ? dict[t[i]]=1 : dict[t[i]]++ ; 
        window[t[i]] = NOT_FOUND; 
    }

    int start =-1;
    int winSize = INT_MAX;
    int letterFound = 0;
    int left = 0;

    for(int right=0; right<s.size(); right++) {
        if ( dict[s[right]] == NOT_EXISTED ){
            continue;
        }

         
        char chr = s[right];
        window[chr]++;

        
        if (window[chr] <= dict[chr]) {
            letterFound++;
        }

        if ( letterFound >= t.size() ) {
            
            char chl = s[left];
            while ( window[chl] == NOT_EXISTED || window[chl] > dict[chl] ) { 
                if (dict[chl] != NOT_EXISTED  ) {
                    
                    window[chl]--; 
                    
                    if (window[chl] < dict[chl] ) letterFound--;
                }
                chl = s[++left];
            }

            
            if(winSize > right - left + 1){
                start = left;
                winSize = right - left + 1;
            }

        }
    }

    if (start>=0 && winSize>0) {
        win = s.substr(start, winSize);
    }
    return win;
}

int main(int argc, char**argv)
{
    string S = "ADOBECODEBANC";
    string T = "ABC";
    if (argc>2){
        S = argv[1];
        T = argv[2];
    }
    cout << "S = \"" << S << "\"  T=\"" << T << "\"" <<endl;
    cout << minWindow(S, T) << endl;
    return 0;
}