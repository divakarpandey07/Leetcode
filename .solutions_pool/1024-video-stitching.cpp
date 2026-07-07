class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {

        
        std::sort(clips.begin(), clips.end(), [](vector<int>& x, vector<int>& y) {
            return x[0] < y[0] || (x[0] == y[0] && x[1] < y[1]);
        });

        

        
        

        vector<int> dp(T+1, -1);
        for (auto c : clips) {
            
            if (c[0] > T) continue;

            
            if (c[0] == 0) {
                for (int i=c[0]; i<=min(T,c[1]); i++) dp[i] = 1;
                continue;
            }

            
            
            
            

            if (dp[c[0]] == -1 ) continue;

            int m = dp[c[0]];

            for (int i = c[0] + 1; i<= min(T, c[1]); i++) {
                if ( dp[i] > 0 ) m = min(m, dp[i]);
                else dp[i] = m + 1;
            }
        }

        
        return dp[T];
    }

    
    void print(vector<vector<int>>& clips) {
        for (auto c : clips) {
            cout << "[" << c[0] <<","<< c[1] << "]"<< " ";
        }
        cout << endl;
    }

    void print(vector<int>& v) {
        for (auto i : v) {
            cout << i << ", ";
        }
        cout << endl;
    }
};