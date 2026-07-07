#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMin(vector<int> &num) {

    int low=0, high=num.size()-1;

    while(high-low>1){
        
        while (high - low > 1 && num[low] == num[high]){
            low++;
        }
        
        int mid = low + (high-low)/2;
        
        
        if (num[low] <= num[mid] && num[mid] <= num[high]){
            return num[low];
        }
        
        if (num[low] > num [mid]){
            high = mid;
            continue;
        }
        
        if (num[mid] > num[high]){
            low = mid;
            continue;
        }
    }
    
    
    if (high == low) return num[low];
    return num[low] < num[high] ? num[low] : num[high];

}

void rotate_array(int a[], int n, int pos){
    int i, from=0;
    pos = pos % n;
    if (n<=0) return;

    int tmp = a[0];

    for(int i=0, step=0; step<n && i<pos; step++){
        int to;
        if (from-pos < 0) {
            to = n-pos+from; 
        }else{
            to = from-pos;
        }
        int t ;
        t = a[to];
        a[to] = tmp; 
        tmp = t;
        from = to;
        if ( to == i ){
            i++;
            from++;
            tmp = a[from];
        }
    }

}

void printArray(int A[], int n) {
    printf("{");
    for(int i=0; i<n; i++) {
        printf("%d, ", A[i]);
    }
    printf("}\n");
}

int main(int argc, char** argv)
{

    int cnt=20;

    if (argc>1) {
        cnt = atoi(argv[1]);
    }

    srand(time(NULL)); 

    int expectedMin, actualMin;
    int *a = new int[cnt];
    for(int n=0; n<=cnt; n++) {
        printf("--------------------------------------\n");
        
        for(int i=0; i<cnt; i++){
            a[i]=rand()%cnt;
        }
        
        sort(a, a+cnt); 
        expectedMin = a[0];
        
        int rotate_pos = random() % cnt;
        
        printf("rotate=%d\n", rotate_pos);
        rotate_array(a, cnt, rotate_pos);
        printArray(a, cnt);

        vector<int> num(a, a+cnt);
        actualMin = findMin(num);
        cout << "findMin = " << actualMin << "   " << (expectedMin==actualMin ? "passed" : "failed") << endl;

    }
    delete[] a;

    return 0;
}