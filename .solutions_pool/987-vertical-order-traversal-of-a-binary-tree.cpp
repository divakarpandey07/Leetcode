class Item {
public:
    Item(int _x, int _y, int _val):x(_x), y(_y),val(_val) {}
    int x, y;
    int val;
};

class ItemCmp {
public:
    bool operator () (const Item &lhs, const Item &rhs) const {
        return lhs.y != rhs.y ? lhs.y > rhs.y : lhs.val < rhs.val;
    }
};

int getValue(const Item& i) {
    return i.val;
}

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        set<int> rows;
        unordered_map<int, set<Item, ItemCmp>> m;

        verticalTraversalHelper(root, 0, 0, rows, m);

        vector<vector<int>> result;
        for(auto r : rows) {
            vector<int> v;
            transform(m[r].begin(), m[r].end(), back_inserter(v), getValue);
            result.push_back(v);
        }
        return result;
    }
    void verticalTraversalHelper(TreeNode* root, int x, int y,
                                 set<int>& rows,
                                 unordered_map<int, set<Item, ItemCmp>>& m) {

        if ( !root ) return;

        rows.insert(x);
        m[x].insert(Item(x, y, root->val));
        verticalTraversalHelper(root->left, x-1, y-1, rows, m); 
        verticalTraversalHelper(root->right, x+1, y-1, rows, m); 

    }
};