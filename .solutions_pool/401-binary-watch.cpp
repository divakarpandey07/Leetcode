class Solution {
private:
    void combination(int nLED, int nLight, int max, bool zero,
                     int start, int k, int solution, 
                     vector<vector<string>>& result) {
        if (solution > max){
            return;
        }
        if (k == 0) {
            char tmp[5] = "";
            if (zero) {
                sprintf(tmp, "%02d", solution);
            }else{
                sprintf(tmp, "%d", solution);
            }
            result[nLight].push_back(tmp);
            return;
        }
        for (int i=start; i<=nLED-k; i++) {
            solution += pow(2, i);
            combination(nLED, nLight, max, zero, i+1, k-1, solution, result);
            solution -= pow(2, i);
        }
    }
    
    void generate_combination(int nLED, int max, bool zero, vector<vector<string>>& result) {
        for (int i=0; i<nLED; i++) {
            combination(nLED, i, max, zero, 0, i, 0, result);
        }
    }
    
    void print(vector<vector<string>>&  vv) {
        for(auto v : vv) {
            cout << "[ ";
            for (auto i : v) {
                cout << i << " ";
            }
            cout << "]" << endl;
        }
    }
    
private:
    vector<vector<string>> hour;
    vector<vector<string>> mins;

public:

    Solution():hour(4, vector<string>()), mins(6, vector<string>()){
        generate_combination(4, 11, false, hour);
        
        
        
        
        
        
        
        generate_combination(6, 59, true, mins);
        
        
        
        
        
        
        
    }
    
    vector<string> readBinaryWatch(int num) {
        
        vector<string> result;
        for (int i = 0; i <= 3 && i <= num; i++) {
            if (num - i > 5) {
                continue;
            }
            for (auto h : hour[i]) {
                for (auto m : mins[num - i]) {
                    result.push_back( h + ":" + m );
                }
            }
            
        }
        return result;
    }
};