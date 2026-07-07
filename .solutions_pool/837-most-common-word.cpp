class Solution {
private:
    bool isLetter(char c) {
        return c >= 'a' && c <= 'z';
    }
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> banned_map, words_map;
        for (auto w:banned) {
            banned_map[w]++;
        }
        
        
        transform(paragraph.begin(), paragraph.end(), paragraph.begin(), ::tolower);
        
        
        for (int i=0; i<paragraph.size(); i++) {
            if ( !isLetter(paragraph[i]) ){
                paragraph[i] = ' ';
            }
        }
        string word;
        for(auto c:paragraph) {
            if (isLetter(c)) { 
                word += c;
            }else{
                if ( word.size()>0 ) {
                    words_map[word]++;
                }
                word="";
            }
        }
        if ( word.size()>0 ) words_map[word]++;
        
        string result;
        int max_cnt=0;
        
        for (auto const& w : words_map) {
            
            if ( banned_map.find(w.first) != banned_map.end() ) {
                continue;
            }
            if (max_cnt < w.second) {
                result = w.first;
                max_cnt = w.second;
            }
        }

        return result;
    }
};