#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxPathSum(TreeNode *root, int& maxSum ) {

    if (NULL == root) return 0;

    
    int left  = maxPathSum(root->left,  maxSum);
    int right = maxPathSum(root->right, maxSum);

    
    
    
    
    
    
    
    int val = root->val;
    int maxBranch = left > right ? max(left + val, val) : max(right + val, val);
    int m = max(left + right + val, maxBranch);

    maxSum = max(maxSum, m);

    return maxBranch;
}

int maxPathSum(TreeNode *root) {
    #define INT_MIN     (-2147483647 - 1)
    int maxSum = INT_MIN;
    maxPathSum(root, maxSum);
    return maxSum;
}

int main()
{
    TreeNode root(1);
    TreeNode left(2);
    TreeNode right(3);
    root.left = &left;
    root.right = &right;
    cout << maxPathSum(&root) << endl; 
    return 0;
}