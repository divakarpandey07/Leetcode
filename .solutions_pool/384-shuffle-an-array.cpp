class Solution {
public:
    Solution(vector<int> nums) : _nums(nums), _solution(nums) {
        srand(time(NULL));
    }
    
    
    vector<int> reset() {
        return _solution = _nums;
    }
    
    
    vector<int> shuffle() {
        
        
        
        int i = _solution.size();
        
        while ( --i > 0 ) {
            int j = rand() % (i+1);
            swap(_solution[i], _solution[j]);
        }
        return _solution;
    }
private:
    vector<int> _nums, _solution;
};