class Solution {
public:
    int getWinner(vector<int>& arr, int k) { 
        
        int left=0, right=1;
        
        int max = arr[left] > arr[right] ? arr[left] : arr[right];
        int winner; 
        int win_times = 0;
        
        while( right < arr.size())  {

            
            if ( arr[left] < arr[right] ) {
                left = right;
            }
            
            right++;
            
            int w = arr[left];            
            
            if (w == winner) {
                
                win_times++; 
            }else{
                
                winner = w;
                win_times = 1;
            }
            
            
            if (win_times >= k) return winner;
            
            
            if (max < arr[right]) max = arr[right];
        }
        
        return max;
    }
};