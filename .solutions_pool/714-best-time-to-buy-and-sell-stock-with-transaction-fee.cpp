class Solution {
private:
    int max(int x, int y) {
        return x > y ? x: y;
    }
    int max(int x, int y, int z) {
        return max(x, max(y,z));
    }

public:

    int maxProfit(vector<int>& prices, int fee) {
        return maxProfit_dp03(prices, fee); 
        return maxProfit_dp02(prices, fee); 
        return maxProfit_dp01(prices, fee); 
    }

    
    
    void genPricesPairs(vector<int> &prices, vector< pair<int, int> > &prices_pairs, int fee){

        int low = -1;
        for (int i=0; i<prices.size()-1; i++){
            
            if (prices[i] < prices[i+1] && low < 0 ) {
                low = i;
            }
            
            if (prices[i] > prices[i+1] && low >= 0) {
                prices_pairs.push_back( make_pair( prices[low], prices[i]) );
                low = -1; 
            }
        }

        
        if ( low >= 0 ) {
            prices_pairs.push_back( make_pair( prices[low], prices[prices.size()-1] ) );
        }

    }

    int maxProfit_dp01(vector<int> &prices, int &fee) {

        vector< pair<int, int> > prices_pairs;
        genPricesPairs(prices, prices_pairs, fee);

        vector<int> dp(prices_pairs.size()+1, 0);

        for (int i=0; i<prices_pairs.size(); i++) {
            for ( int j=0; j<=i; j++ ) {
                int profit = prices_pairs[i].second - prices_pairs[j].first - fee;
                
                if ( profit < 0 ) profit = 0;
                dp[i+1] = max ( dp[i+1], dp[j] + profit);
            }
        }

        return dp[dp.size()-1];
    }

    int maxProfit_dp02(vector<int> &prices, int &fee) {

        vector< pair<int, int> > prices_pairs;
        genPricesPairs(prices, prices_pairs, fee);

        if ( prices_pairs.size() < 1 ) return 0;

        
        
        vector< pair<int,int> > dp(prices_pairs.size() , make_pair(0,0) );

        
        dp[0].first = - prices_pairs[0].first;

        
        
        dp[0].second = max(0, prices_pairs[0].second - prices_pairs[0].first - fee);

        for (int i=1; i<prices_pairs.size(); i++) {
            
            
            
            
            

            dp[i].first = max (dp[i-1].first,                          
                               dp[i-1].second - prices_pairs[i].first, 
                               - prices_pairs[i].first );              

            
            
            
            
            
            dp[i].second = max(dp[i-1].second,
                               dp[i-1].first + prices_pairs[i].second - fee,
                               dp[i-1].second + prices_pairs[i].second - prices_pairs[i].first - fee );
        }

        return max( dp[dp.size()-1].second, 0 );

    }

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    int maxProfit_dp03(vector<int> &prices, int &fee) {
        int buy=-prices[0], sell=0;
        int pre_buy=0, pre_sell=0;

        for(auto price: prices) {
            pre_buy = buy;
            buy = max (sell - price, pre_buy);

            pre_sell = sell;
            sell = max( pre_buy + price - fee, pre_sell);
        }

        return sell;
    }
};