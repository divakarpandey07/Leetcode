class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int current = 0;
        int start = gas.size(); 
        int total = 0;
        
        do {
            if (total + gas[current] - cost[current] >= 0) {
                total += (gas[current] - cost[current]);
                current++; 
            }else{
                start--; 
                total += (gas[start] - cost[start]);
            }
        } while(current != start);
        
        return total>=0 ? start % gas.size() : -1;
    }
};