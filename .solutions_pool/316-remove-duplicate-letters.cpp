class Solution {
public:
    string removeDuplicateLetters(string s) {
        const int ASCII_LEN = 256;
        int counter[ASCII_LEN] = {0};
        bool visited[ASCII_LEN] = {false};
        
        for (char ch : s) {
            counter[ch]++;
        }
        
        string result;
        for (char ch : s) {
            counter[ch]--;
            
            if (visited[ch]) continue;
            
            
            
            while ( !result.empty() && ch < result.back() && counter[result.back()] ) {
                visited[result.back()] = false;
                result.pop_back();
            }
            result.push_back(ch);
            visited[ch] = true;
        }
        return result;
    }
};