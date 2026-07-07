#include <stdlib.h>
#include <iostream>
using namespace std;

int rangeBitwiseAnd(int m, int n) {
    int mask = 0xffffffff;

    
    while (mask != 0) {
        if ((m & mask) == (n & mask)) {
            break;
        }
        mask <<= 1;
    }

    return m & mask;

}

int main(int argc, char**argv) {
    int m=5, n=7;
    if (argc>2){
        m = atoi(argv[1]);
        n = atoi(argv[2]);
    }
    cout << "range( " << m << ", " << n << " ) = " <<  rangeBitwiseAnd(m, n) << endl;
    return 0;
}