class Solution {
public:
    int numSplits(string s) {
        
        
        
        
        
        const int max_chars= 256;
        vector<bool> ldict(max_chars, false), rdict(max_chars, false);
        
        
        
        
        int len = s.size();
        vector<int> lstat(len, 0), rstat(len, 0);
        
        int lcnt=0, rcnt=0;
        
        for (int i=0; i<len; i++) {
            char lc = s[i];
            char rc = s[len-i-1];
            
            if (ldict[lc] == false) {
                lcnt++;
                ldict[lc] = true;
            }
            
            if (rdict[rc] == false) {
                rcnt++;
                rdict[rc] = true;
            }
            
            lstat[i] = lcnt;
            rstat[len-i-1] = rcnt;
        }
        
        
        int cnt = 0;
        for (int i=1; i<len; i++){
            if (lstat[i-1] == rstat[i]) {
                cnt++;
            }
        }
        
        return cnt;
        
    }
};