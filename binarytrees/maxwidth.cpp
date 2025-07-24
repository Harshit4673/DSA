// leetcode 662
#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
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
    // Time: O(N) | Space: O(N)
    // Performs level-order traversal assigning virtual indices to calculate width of each level
    int widthOfBinaryTree(TreeNode *root)
    {
        if (!root)
            return 0;

        long long ans = 0;
        queue<pair<TreeNode *, long long>> q;
        q.push({root, 0});

        while (!q.empty())
        {
            int size = q.size();
            long long mmin = q.front().second; // normalize indices to prevent overflow
            long long first = 0, last = 0;

            for (int i = 0; i < size; i++)
            {
                long long cur_id = q.front().second - mmin;
                TreeNode *node = q.front().first;
                q.pop();

                if (i == 0)
                    first = cur_id;
                if (i == size - 1)
                    last = cur_id;

                if (node->left)
                    q.push({node->left, cur_id * 2 + 1});
                if (node->right)
                    q.push({node->right, cur_id * 2 + 2});
            }

            ans = max(ans, last - first + 1);
        }

        return static_cast<int>(ans);
    }
};

// Sample driver code
int main()
{
    /*
           1
         /   \
        3     2
       /       \
      5         9
     /           \
    6             7

    Expected maximum width: 8 (from node 6 to node 7)
    */

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->right->right = new TreeNode(9);
    root->left->left->left = new TreeNode(6);
    root->right->right->right = new TreeNode(7);

    Solution sol;
    int result = sol.widthOfBinaryTree(root);

    cout << "Maximum width of binary tree: " << result << endl;

    return 0;
}
    