#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

vector<int> findSubstring(string S, vector<string> &L) {

    vector<int> result;
    if ( S.size()<=0 || L.size() <=0 ){
        return result;
    }
    
    int n = S.size(), m = L.size(), l = L[0].size();

    
    map<string, int> expected;
    for(int i=0; i<m; i++){
        if (expected.find(L[i])!=expected.end()){
            expected[L[i]]++;
        }else{
            expected[L[i]]=1;
        }
    }

    for (int i=0; i<l; i++){
        map<string, int> actual;
        int count = 0; 
        int winLeft = i;
        for (int j=i; j<=n-l; j+=l){
            string word = S.substr(j, l);
            
            if (expected.find(word) == expected.end() ) {
                actual.clear();
                count=0;
                winLeft = j + l;
                continue;
            }
            count++;
            
            if (actual.find(word) == actual.end() ) {
                actual[word] = 1;
            }else{
                actual[word]++;
            }
            
            if (actual[word] > expected[word]){
                string tmp;
                do {
                    tmp = S.substr( winLeft, l );
                    count--;
                    actual[tmp]--;
                    winLeft += l; 
                } while(tmp!=word);
            }

            
            if ( count == m ){
                result.push_back(winLeft);
                string tmp = S.substr( winLeft, l );
                actual[tmp]--;
                winLeft += l;
                count--;
            }
            
        }
    }

    return result;
}

int main(int argc, char**argv)
{
    string s = "barfoobarfoothefoobarman";
    vector<string> l;
    l.push_back("foo");
    l.push_back("bar");
    l.push_back("foo");
    
    vector<int> indics = findSubstring(s, l);
    
    for(int i=0; i<indics.size(); i++){
        cout << indics[i] << " ";
    }
    cout << endl;

    return 0;
}