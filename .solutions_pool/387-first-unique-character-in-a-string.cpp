class Solution {
public:
    int firstUniqChar(string s) {
        
        
        #define MAX_CHAR 256
        #define NOT_FOUND  -1
        #define DUPLICATION -2
        
        
        int pos_map[MAX_CHAR];
        memset(pos_map, NOT_FOUND,sizeof(pos_map));
        
        
        
        
        for (int i=0; i<s.size(); i++){
            if ( pos_map[s[i]] >= 0 ) {
                pos_map[s[i]] = DUPLICATION;
            }else if ( pos_map[s[i]] == NOT_FOUND ) {
                pos_map[s[i]] = i;
            }
        }
        
        
        int pos = INT_MAX;
        for (auto item : pos_map) {
            cout << item << ",";
            if (item >= 0 && item < pos) {
                pos = item;
            }
        }
        return pos == INT_MAX ? -1 : pos;
    }
};