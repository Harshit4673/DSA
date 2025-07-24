// leetcode 100
#include <iostream>
using namespace std;

// Definition for a binary tree node
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution
{
public:
    // Time: O(N) | Space: O(H)
    // Recursively compare values and structure of both trees (DFS)
    bool dfs(TreeNode *p, TreeNode *q)
    {
        if (!p && !q)
            return true;
        if (!p || !q)
            return false;
        if (p->val != q->val)
            return false;
        return dfs(p->left, q->left) && dfs(p->right, q->right);
    }

    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        return dfs(p, q);
    }
};

// Sample driver code
int main()
{
    /*
    Tree 1:       1
                 / \
                2   3

    Tree 2:       1
                 / \
                2   3
    */

    TreeNode *p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    TreeNode *q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    Solution sol;
    bool result = sol.isSameTree(p, q);

    cout << "Trees are " << (result ? "the same." : "different.") << endl;

    return 0;
}
