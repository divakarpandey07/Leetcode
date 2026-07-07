class Solution {
public:
    int maxProfit(vector<int>& prices) {
        return maxProfit02(prices);
        return maxProfit01(prices);
    }
    
    
    
    
    int maxProfit01(vector<int> &prices) {

        int max = 0;
        int low = -1;
	int len = prices.size();
        for (int i=0; i < len - 1; i++){
            
            if (prices[i] < prices[i+1] && low < 0 ) {
                low = i;
            }
            
            if (prices[i] > prices[i+1] && low >= 0) {
                max += ( prices[i] - prices[low] ) ;
                low = -1; 
            }
        }

        
        if ( low >= 0 ) {
            max += ( prices[prices.size()-1] - prices[low] );
        }

        return max;
    }

    
    
    int maxProfit02(vector<int>& prices) {
        int profit = 0 ;
        for(int i=1; i< prices.size(); i++) {
            profit += max(0, prices[i] - prices[i-1]);
        }
        return profit;
    }
};