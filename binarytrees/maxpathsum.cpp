//leetcode 124
#include <iostream>
#include <climits>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    // Function: Checks if two trees are identical
    // Time: O(n), Space: O(h) where h = height of tree
    // Uses DFS to compare node values and structure
    bool dfs(TreeNode* p, TreeNode* q) {
        if (!p && !q)
            return true;
        if (!p || !q)
            return false;
        if (p->val != q->val)
            return false;
        return dfs(p->left, q->left) && dfs(p->right,q->right);
    }

    // Wrapper for dfs
    // Time: O(n), Space: O(h)
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return dfs(p, q);
    }

    // Function: Checks if tree is height-balanced
    // Time: O(n), Space: O(h)
    // Returns -1 if subtree is unbalanced, else returns height
    int balance(TreeNode* root) {
        if (root == NULL)
            return 0;
        int left = balance(root->left);
        int right = balance(root->right);
        if(left == -1 || right == -1){
            return -1;
        }
        if (abs(left - right) > 1)
            return -1;
        return max(left, right) + 1;
    }

    // Wrapper for balance function
    // Time: O(n), Space: O(h)
    bool isBalanced(TreeNode* root) {
        return balance(root) != -1;
    }

    // Function: Finds max width of binary tree (using level-order + indexing)
    // Time: O(n), Space: O(n)
    int widthOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0;

        long long ans = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();
            long long mmin = q.front().second;
            long long first = 0, last = 0;

            for (int i = 0; i < size; i++) {
                long long cur_id = q.front().second - mmin;
                TreeNode* node = q.front().first;
                q.pop();

                if (i == 0) first = cur_id;
                if (i == size - 1) last = cur_id;

                if (node->left)
                    q.push({node->left, cur_id * 2 + 1});
                if (node->right)
                    q.push({node->right, cur_id * 2 + 2});
            }

            ans = max(ans, last - first + 1);
        }

        return static_cast<int>(ans);
    }

    // Function: Returns maximum path sum in binary tree
    // Time: O(n), Space: O(h)
    // Uses DFS to find max path through or ending at each node
    int dfs(TreeNode* root, int& maxsum) {
        if(root == NULL) return 0;
        int left = max(0, dfs(root->left, maxsum));
        int right = max(0, dfs(root->right, maxsum));
        int sum = left + right + root->val;

        maxsum = max(maxsum, sum);
        return root->val + max(left, right);
    }

    // Wrapper for max path sum calculation
    // Time: O(n), Space: O(h)
    int maxPathSum(TreeNode* root) {
        int maxVal = INT_MIN;
        dfs(root, maxVal);
        return maxVal;
    }
};
