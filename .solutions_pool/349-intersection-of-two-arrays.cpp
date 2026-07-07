class Solution {
public:
    set <int> inter1, inter2;
    vector <int> solution;
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        for(int i = 0; i < nums1.size(); i++)
            inter1.insert(nums1[i]);
        for(int i = 0; i < nums2.size(); i++)
            if(inter1.find(nums2[i]) != inter1.end())
                inter2.insert(nums2[i]);
        for(set<int>::iterator it = inter2.begin(); it != inter2.end(); ++it)
            solution.push_back(*it);
        return solution;
    }
};

class Solution2 {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> hash_set(nums1.begin(), nums1.end());
        vector<int> res ;
        for (auto it& : nums2) {
            if (hash_set.count(it)) {
                res.push_back(it);
                hash_set.erase(it);
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, bool> m;
        for (auto n : nums1) {
            m[n] = true;
        }
        vector<int> result;
        for (auto n : nums2){
            if (m.find(n) != m.end() && m[n] ){
                result.push_back(n);
                m[n]=false;
            }                    
        }
        return result;
    }
};