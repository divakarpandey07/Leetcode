class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int cnt = 0;
        for(int i=0; i<costs.size() && costs[i] <= coins; i++) {
            cnt++;
            coins -= costs[i];
        }
        return cnt;
    }
};