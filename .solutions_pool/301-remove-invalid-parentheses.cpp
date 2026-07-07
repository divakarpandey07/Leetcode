#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

void removeInvalidParenthesesHelper(string& s, int index, int pair,
                                    int remove_left, int remove_right, 
                                    string solution, unordered_set<string>& result) {

    char ch = s[index];

    
    if ( ch == '\0' ) {
        if (pair==0 && remove_left==0 && remove_right==0 ) {
            result.insert(solution);
        }
        return;
    }
    
    if ( ch != '(' && ch != ')' ) {
        removeInvalidParenthesesHelper(s, index+1, pair, remove_left, remove_right, solution+ch, result);
        return;
    }
    
    
    
    if ( ch == '(' ) {
        
        if (remove_left > 0 ) { 
            removeInvalidParenthesesHelper(s, index+1, pair, remove_left-1, remove_right, solution, result);
        }
        
        removeInvalidParenthesesHelper(s, index+1, pair+1, remove_left, remove_right, solution+ch, result);
    }
    
    
    
    if ( ch == ')' ) {
        if (remove_right > 0 ) {
            removeInvalidParenthesesHelper(s, index+1, pair, remove_left, remove_right-1, solution, result);
        }
        if (pair > 0){
            removeInvalidParenthesesHelper(s, index+1, pair-1, remove_left, remove_right, solution+ch, result);
        }
    }

}

vector<string> removeInvalidParentheses(string s) {

    
    int remove_left = 0, remove_right = 0;
    for(auto c : s) {
        if ( c == '(' ) {
            remove_left++;
        }else if ( c == ')' ){
            if (remove_left > 0) {
                remove_left--; 
            }else{
                remove_right++;
            }
        }
    }

    unordered_set<string> result;
    removeInvalidParenthesesHelper(s, 0, 0, remove_left, remove_right, "", result);
    return vector<string>( result.begin(), result.end() );
}

void printVector(vector<string> result) {
    for( int i=0; i<result.size(); i++) {
        cout << i << ") " << result[i] << endl;
    }
}

int main(int argc, char** argv) {
    string s = "()())()";
    if (argc>1) {
        s = argv[1];
    }
    cout << s << endl;
    printVector( removeInvalidParentheses(s) );
    
    return 0;
}