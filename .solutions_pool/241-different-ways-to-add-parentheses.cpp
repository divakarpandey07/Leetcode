#include <stdlib.h>
#include <ctype.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

bool isOperator(char ch){
    return (ch=='+' || ch=='-' || ch=='*');
}

vector<int> diffWaysToCompute(string input) {
    
    static map< string, vector<int> > cache;
    if ( cache.find(input) != cache.end() ){
        return cache[input];
    }

    vector<int> result; 
    for (int i=0; i<input.size(); i++){
        char ch = input[i];
        if (isOperator(ch)){
            
            
            string left  = input.substr(0, i);
            string right = input.substr(i+1);
            vector<int> lv = diffWaysToCompute(left);
            vector<int> rv = diffWaysToCompute(right);

            
            for(int li=0; li<lv.size(); li++) {
                for(int ri=0; ri<rv.size(); ri++) {
                    switch(ch){
                        case '+' : result.push_back(lv[li] + rv[ri]); break;
                        case '-' : result.push_back(lv[li] - rv[ri]); break;
                        case '*' : result.push_back(lv[li] * rv[ri]); break;
                    }
                }
            }

        }
    }
    
    
    if (result.size()==0) {
        result.push_back(atoi(input.c_str()));
    }
    
    
    cache[input] = result;

    return result;
}

void printVector(vector<int>& v) {
    cout << "[";
    for(int i=0; i<v.size(); i++) {
        cout << v[i] << (i==v.size()-1 ? "]":", ");
    }
    cout << endl;
}

int main(int argc, char**argv) 
{
    string exp = "2*3-4*5";
    if ( argc > 1 ){
        exp = argv[1];
    }
    vector<int> v = diffWaysToCompute(exp);
    cout << exp << endl;
    printVector(v);
    return 0;
}