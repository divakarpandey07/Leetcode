class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> m;
        for(int i=0; i<magazine.size(); i++) {
            m[magazine[i]]++;
        }
        for (int i=0; i<ransomNote.size(); i++) {
            char c = ransomNote[i];
            if (m[c] <=0 ) return false;
            m[c]--;
        }
        return true;
    }
};