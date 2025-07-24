//leetcode 110
#include <iostream>
#include <cmath>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Time: O(N) | Space: O(H)
    // Recursively checks subtree height; if difference > 1, marks unbalanced
    int balance(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int left = balance(root->left);
        int right = balance(root->right);

        if (left == -1 || right == -1)
            return -1;

        if (abs(left - right) > 1)
            return -1;

        return max(left, right) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return balance(root) != -1;
    }
};

// Sample driver code
int main() {
    /*
        Balanced Tree:
              1
             / \
            2   3
           /
          4

        Unbalanced Tree:
              1
             /
            2
           /
          3
    */

    TreeNode* balanced = new TreeNode(1);
    balanced->left = new TreeNode(2);
    balanced->right = new TreeNode(3);
    balanced->left->left = new TreeNode(4);

    TreeNode* unbalanced = new TreeNode(1);
    unbalanced->left = new TreeNode(2);
    unbalanced->left->left = new TreeNode(3);

    Solution sol;

    cout << "Balanced Tree is " << (sol.isBalanced(balanced) ? "balanced." : "not balanced.") << endl;
    cout << "Unbalanced Tree is " << (sol.isBalanced(unbalanced) ? "balanced." : "not balanced.") << endl;

    return 0;
}
