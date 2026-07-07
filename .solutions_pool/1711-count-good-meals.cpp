class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        const int MAX_EXP = 22;
        int pow2[MAX_EXP];
        for (int i=0; i<MAX_EXP; i++){
            pow2[i] = 1 << i;
            
        }
        
        unordered_map<int, int> stat;
        int big = 0;
        for(auto& d: deliciousness){
            stat[d]++;

        }

        long m = 0;
        for(auto& d: deliciousness){
            for(int i=MAX_EXP-1; i>=0 && pow2[i] >= d; i--){
                int x = pow2[i] - d;
                if ( stat.find(x) != stat.end() ){
                    m += (x==d) ? stat[x]-1 : stat[x];
                }
            }
        }
        
        
        
        return (m/2) % 1000000007;
    }
};