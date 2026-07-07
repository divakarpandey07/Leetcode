class Node{
    public:
        long long val;
        int cnt; 
        Node *left, *right;
        Node(long long v):val(v), cnt(1), left(NULL), right(NULL) {}
};

class Tree{
    public:
        Tree():root(NULL){ }
        ~Tree() { freeTree(root); }
        
        void Insert(long long val) {
            Insert(root, val);
        }
        int LessThan(long long sum, int val) {
            return LessThan(root, sum, val, 0);
        }
        
    private:
        Node* root;
        
        
        void Insert(Node* &root, long long val) {
            if (!root) {
                root = new Node(val);
                return;
            }
            
            root->cnt++;
            
            if (val < root->val ) {
                Insert(root->left, val);
            }else if (val > root->val) {
                Insert(root->right, val);
            }
        }
        
        
        
        int LessThan(Node* root, long long sum, int val, int res) {
            
            if (!root) return res;

            if ( sum - root->val < val) {
                
                
                res += (root->cnt - (root->left ? root->left->cnt : 0) );
                return LessThan(root->left, sum, val, res);
            }else if ( sum - root->val > val) {
                
                
                return LessThan(root->right, sum, val, res);
            }else {
                
                
                return res + (root->right ? root->right->cnt : 0);
            }
        }
        void freeTree(Node* root){
            if (!root) return;
            if (root->left) freeTree(root->left);
            if (root->right) freeTree(root->right);
            delete root;
        }
        
};

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        Tree tree;
        tree.Insert(0);
        long long sum = 0;
        int res = 0;
        
        for (int n : nums) {
            sum += n;
            int lcnt = tree.LessThan(sum, lower);
            int hcnt = tree.LessThan(sum, upper + 1);
            res += (hcnt - lcnt);
            tree.Insert(sum);
        }

        return res;
    }
};