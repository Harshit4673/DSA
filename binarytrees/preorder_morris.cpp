//leetcode 144
#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 */
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;

        while (curr != NULL) {
            if (curr->left == NULL) {
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else {
                TreeNode* prev = curr->left;
                while (prev->right && prev->right != curr) {
                    prev = prev->right;
                }

                if (prev->right == NULL) {
                    prev->right = curr;
                    ans.push_back(curr->val);
                    curr = curr->left;
                }
                else {
                    prev->right = NULL;
                    curr = curr->right;
                }
            }
        }

        return ans;
    }
};

// Time Complexity: O(n) — each node is visited at most twice (due to threading)
// Space Complexity: O(1) — Morris traversal uses constant space (no recursion or stack)
// Function Purpose: Performs preorder traversal of a binary tree using Morris Traversal (threaded binary tree concept)
