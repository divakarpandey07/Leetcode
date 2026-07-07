class Solution {
public:
    string removeKdigits_pick(string& num, int k) {
        
        int len = num.size();
        string result;
        
        int idx = 0;
        for (int i=0; i < len - k; i++) {
            int min_idx = idx;
            for (int j=min_idx; j<=i+k; j++) {
                if (num[min_idx] > num[j])  min_idx = j;
            }
            
            
            if ( !(result.empty() && num[min_idx]=='0') ){
                result.push_back(num[min_idx]);
            }
            
            
            idx = min_idx + 1;
        }
        
        if (result.empty()) result = "0";
        return result;
    }
    
    string removeKdigits_remove(string& num, int k) {
        if ( num.size() <= k ) return "0";
        int left_len = num.size() - k;
        int idx = 0;
        for (int i=0; i<k ;i++){
            int len = num.size();
            for (int j=0; j<num.size()-1; j++) {
                
                
                if ( num[j] > num[j+1] ) {
                    num.erase(j, 1);
                    idx = j;
                    break;
                }
            }
        }
        
        
        for (int i=0; i<= num.size(); i++) {
            if (num[i] != '0' || i == num.size()) {
                num.erase(0, i);
                break;
            }
        }
        
        
        
        if (num.size() > left_len ) {
            num.erase(num.begin() + left_len, num.end());
        }
        
        if (num.empty()) num = "0";
        return num;
    }
    
    string removeKdigits(string num, int k) {
        srand(time(0));
        if (rand() % 2 ) {
            return removeKdigits_pick(num, k);
        } else {
            return removeKdigits_remove(num, k);
        }
    }
};