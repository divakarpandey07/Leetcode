#include <iostream>
#include <algorithm>
using namespace std;

int max(int x, int y) {
    return x>y?x:y;
}
int min(int x, int y){
    return x<y?x:y;
}
int max(int x, int y, int z) {
    return max(x, max(y,z));
}
int min(int x, int y, int z) {
    return min(x, min(y, z));
}

int maxProduct(int A[], int n) {

    
    int maxPrev = A[0], minPrev = A[0];
    
    int maxHere = A[0], minHere = A[0];
    
    int maxProd = A[0];

    for (int i=1; i<n; i++){
        maxHere = max( maxPrev * A[i], minPrev * A[i], A[i] );
        minHere = min( maxPrev * A[i], minPrev * A[i], A[i] );
        
        maxProd = max(maxHere, maxProd);
        
        maxPrev = maxHere;
        minPrev = minHere;
    }
    return maxProd;    
}

#define TEST(a)    cout << maxProduct( a, sizeof(a)/sizeof(int)) << endl
int main()
{
    int o[] = {2,3,-2,4};
    TEST(o);

    int a[] = {-4,-3};
    TEST(a);

    int b[] = {-1, -1};
    TEST(b);

    int c[] = {-1, 0, -2};
    TEST(c);
}