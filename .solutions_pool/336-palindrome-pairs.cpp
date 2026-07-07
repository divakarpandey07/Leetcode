class Solution {
public:
    bool isPalindrome(string& str) {
        int left = 0, right = str.size() - 1;
        while( left < right) {
            if (str[left++] != str[right--]) return false;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> dict;
        for(int i=0; i<words.size(); i++){
            string w = words[i];
            reverse(w.begin(), w.end());
            dict[w] = i;
        }
        
        
        vector<vector<int>> result;
        
        
        if ( dict.find("") != dict.end() ) {
            for(int i=0; i<words.size(); i++) {
                if ( isPalindrome(words[i]) && dict[""] != i ) {
                    result.push_back( { dict[""], i } );
                }
            }
        }
        
        for(int i=0; i<words.size(); i++) {
            for (int j=0; j<words[i].size(); j++) {
                
                string left = words[i].substr(0, j);
                string right = words[i].substr(j, words[i].size() - j);
                
                
                
                if ( dict.find(left) != dict.end() && isPalindrome(right) && dict[left] != i ) {
                    result.push_back( { i, dict[left] } );
                }
                
                if (dict.find(right) != dict.end() && isPalindrome(left) && dict[right] != i ) {
                    result.push_back( { dict[right], i } );
                }
            }

        }
        
        return result;
    }
    
};