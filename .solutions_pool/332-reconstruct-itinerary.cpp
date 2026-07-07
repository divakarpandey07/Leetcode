class Solution {
public:
    
    void travel(string& start, unordered_map<string, multiset<string>>& map, vector<string>& result) {
        while (map[start].size() > 0 ) {
            string next = *(map[start].begin());
            map[start].erase(map[start].begin());
            travel(next, map, result);
        }
        result.insert(result.begin(), start);
    }
    
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string, multiset<string>> map;
        for(auto t : tickets) {
            map[t.first].insert(t.second);
        }
        vector<string> result;
        string start = "JFK";
        travel(start, map, result);
        return result;
    }
};