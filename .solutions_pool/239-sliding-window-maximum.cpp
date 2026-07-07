#include <iostream>
#include <vector>
#include <deque>
#include <set>
using namespace std;

vector<int> maxSlidingWindow02(vector<int>& nums, int k) {
    vector<int> result;

    
    multiset<int> w;

    for(int i=0; i<nums.size(); i++) {
        
        if (i >= k) {
            w.erase(w.find(nums[i-k]));
        }
        
        w.insert(nums[i]);
        if (i>=k-1) {
            result.push_back(*w.rbegin());
        }
    }

    return result;
}

vector<int> maxSlidingWindow01(vector<int>& nums, int k) {
    vector<int> result;

    
    deque<int> q;

    for(int i=0; i<nums.size(); i++) {
        
        if (!q.empty() && q.front() == i - k) {
            q.pop_front();
        }
        
        while (!q.empty() && nums[q.back()] < nums[i]) {
            q.pop_back();
        }
        
        q.push_back(i);
        if (i>=k-1) {
            result.push_back(nums[q.front()]);
        }
    }

    return result;
}

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    return maxSlidingWindow01(nums, k);
    return maxSlidingWindow02(nums, k);
}

void printVector( vector<int>& v ) {
    cout << "{ ";
    for(int i=0; i<v.size(); i++) {
        cout << v[i] << (i==v.size() ? " ": ", ");
    }
    cout << "}" << endl;
}

int main(int argc, char** argv) 
{
    int a[] = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> nums(a, a+sizeof(a)/sizeof(a[0]));
    printVector(nums);
    vector<int> result = maxSlidingWindow(nums, k);
    printVector(result);
}