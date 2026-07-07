class Solution {
    public:
        

        int maxProfit(int k, vector<int> &prices) {
            int ndays = prices.size();

            
            if (ndays<=1) return 0;

            
            
            
            
            
            
            if(k > ndays/2){
                int sum = 0;
                for (int i=1; i<ndays; i++) {
                    sum += max(prices[i] - prices[i-1], 0);
                }
                return sum;
            }

            return maxProfit_DP03(k, prices);
            return maxProfit_DP02(k, prices);
            return maxProfit_DP01(k, prices);
        }

        
        int maxProfit_DP01 (int k, vector<int> &prices) {
            int ndays = prices.size();
            vector< vector<int> > profits(k+1, vector<int>( ndays+1, 0));
            for(int trans=1; trans<=k; trans++) {
                for (int day=1; day<=ndays; day++) {
                    int m=0;
                    for (int i=1; i<=day; i++) {
                        m = max(m, profits[trans-1][i-1]+ prices[day-1] - prices[i-1]);
                    }
                    profits[trans][day] =  max( profits[trans][day-1], m);
                }
            }
            return profits[k][ndays];
        }

        
        
        

        int maxProfit_DP02 (int k, vector<int> &prices) {

            int ndays = prices.size();

            vector< vector<int> > profits(k+1, vector<int>( ndays+1, 0));
            vector<int> m(ndays+1, 0); 

            for(int trans=1; trans<=k; trans++) {
                m[0] = profits[trans-1][0] - prices[0];
                for (int day=1; day<=ndays; day++) {
                    profits[trans][day] =  max( profits[trans][day-1], m[day-1]+prices[day-1]);
                    if (day < ndays) {
                        m[day] = max(m[day-1], profits[trans-1][day] - prices[day]);
                    }
                }
            }
            return profits[k][ndays];
        }

        
        int maxProfit_DP03 (int k, vector<int> &prices) {
            int ndays = prices.size();
            vector< vector<int> > profits(k+1, vector<int>( ndays+1, 0));

            for(int trans=1; trans<=k; trans++) {
                int m = profits[trans-1][0] - prices[0];
                for (int day=1; day <= ndays; day++) {
                    profits[trans][day] = max(profits[trans][day-1], m + prices[day-1]);
                    if ( day < ndays ) {
                        m = max(m, profits[trans-1][day] - prices[day]);
                    }
                }
            }

            return profits[k][ndays];
        }
};