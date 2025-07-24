// leetcode 199
#include <iostream>
#include <vector>
#include <queue>
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
    // BFS with right-to-left traversal; first node at each level is the right view
    vector<int> rightSideView(TreeNode *root)
    {
        queue<TreeNode *> q;
        vector<int> ans;

        if (!root)
            return ans;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            ans.push_back(q.front()->val); // First node seen from right

            for (int i = 0; i < size; ++i)
            {
                TreeNode *temp = q.front();
                q.pop();

                if (temp->right)
                    q.push(temp->right);
                if (temp->left)
                    q.push(temp->left);
            }
        }
        return ans;
    }
};

// Sample driver code
int main()
{
    /*
           1
          / \
         2   3
          \    \
           5    4
    */
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    Solution sol;
    vector<int> result = sol.rightSideView(root);

    cout << "Right side view: ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
