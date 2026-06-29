class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void solve(int i, vector<int>& nums) {
        ans.push_back(temp);

        for (int j = i; j < nums.size(); j++) {
            temp.push_back(nums[j]);
            solve(j + 1, nums);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        solve(0, nums);
        return ans;
    }
};