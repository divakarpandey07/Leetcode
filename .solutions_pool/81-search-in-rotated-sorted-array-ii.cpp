class Solution {
public:
    bool search(int A[], int n, int key) {
        if (n<=0) return false;
    
        if (n==1){
            return (A[0]==key) ? true : false;
        }
        int low=0, high=n-1;
        while( low<=high ){
    
            if (A[low] < A[high] && ( key < A[low] || key > A[high]) ) {
                 return false;
            }
            
            
            while (low < high && A[low]==A[high]){
                low++;
            }
    
            int mid = low + (high-low)/2;
            if ( A[mid] == key ) return true;
    
            
            if (A[low] < A[mid] && key >= A[low] && key< A[mid]){
                high = mid - 1;
                continue;
            }
            
            if (A[mid] < A[high] && key > A[mid] && key <= A[high] ){
                low = mid + 1;
                continue;
            }
            
            if (A[low] > A[mid] ){
                high = mid - 1;
                continue;
            }
            
            if (A[mid] > A[high] ){
                low = mid + 1;
                continue;
            }
            
            
            low++;
        }
        return false;
    }
    
    
};