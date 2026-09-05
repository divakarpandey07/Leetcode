class Solution {
public double findMedianSortedArrays(int[] nums1, int[] nums2){
        int merge[]=mergeArr(nums1,nums2);
         int i=merge.length/2;
        if(merge.length%2==0){
            return (merge[i]+merge[i-1])/2.0f;
        }else{
            return merge[i];
        }
    }
    public int [] mergeArr(int a1[], int a2[]){
        int merge[]=new int[a1.length+a2.length];
        int i=0,j=0,k=0;
        while(i<a1.length && j<a2.length){
            if (a1[i]<a2[j]){
                merge[k++]=a1[i++];
            }else{
                merge[k++]=a2[j++];
            }
        }
        while(i<a1.length){
            merge[k++]=a1[i++];
        }
        while(j<a2.length){
            merge[k++]=a2[j++];
        }
        return merge;
    }
};