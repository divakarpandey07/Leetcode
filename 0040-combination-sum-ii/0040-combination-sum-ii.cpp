class Solution {
public:
    void solve(int i, int target, vector<int>& arr, vector<int>& temp, vector<vector<int>>& ans) {

        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int j = i; j < arr.size(); j++) {

            if (j > i && arr[j] == arr[j - 1])
                continue;

            if (arr[j] > target)
                break;

            temp.push_back(arr[j]);
            solve(j + 1, target - arr[j], arr, temp, ans);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> temp;

        solve(0, target, candidates, temp, ans);

        return ans;
    }
};