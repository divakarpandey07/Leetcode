#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void nextPermutation(vector<int>& num); 

string getPermutation(int n, int k) {
    vector<int> num;
    int total = 1;
    for(int i=1; i<=n; i++){
        num.push_back(i);
        total *= i;
    }

    
    if( total < k ) {
        return "";
    }

    
    
    
    
    
    int group = total;
    stringstream ss;
    while (n>0) {
        group = group / n;
        int idx = (k-1) / group;
        ss << num[idx];
        num.erase(num.begin()+idx);
        n--;
        
        
        k -= group * idx;
    }

    return ss.str();
}

string getPermutation_0(int n, int k) {
    vector<int> num;
    int total = 1;
    for(int i=1; i<=n; i++){
        num.push_back(i);
        total *= i;
    }

    
    if( total < k ) {
        return "";
    }
    int group = total / n;
    int idx = (k-1) / group;
    int nn = num[idx];
    num.erase(num.begin()+idx);
    num.insert(num.begin(), nn);

    int offset = (k-1) % group;
    for(int i=0; i<offset; i++) {
        nextPermutation(num);
    }

    
    stringstream ss;
    for(int i=0; i<n; i++){
        ss << num[i];
    }

    return ss.str();
}

string getPermutation_1(int n, int k) {
    vector<int> num;
    for(int i=1; i<=n; i++){
        num.push_back(i);
    }

    for(int i=1; i<k; i++) {
        nextPermutation(num);
    }

    
    stringstream ss;
    for(int i=0; i<n; i++){
        ss << num[i];
    }

    return ss.str();
}

void nextPermutation(vector<int>& num) {
    if (num.size()<=1) return;
    for (int i=num.size()-1; i>0; i-- ) {
        if (num[i-1] < num[i]) {
            int j = num.size() - 1;
            while( num[i-1] > num[j] ) {
                j--;
            }
            int temp = num[i-1];
            num[i-1] = num[j];
            num[j] = temp;

            reverse(num.begin()+i, num.end());
            return;
        }
    }

    reverse( num.begin(), num.end() );
}

int main(int argc, char**argv)
{
    int n=3, k=6;
    if ( argc > 2 ) {
        n = atoi(argv[1]);
        k = atoi(argv[2]);
    }
    cout << "n = " << n << ", k = " << k << " : " << getPermutation(n, k) << endl;

    return 0;
}