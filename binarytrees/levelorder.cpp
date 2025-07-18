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
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == nullptr)
            return ans;

        vector<int> sm;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);

        while (!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();

            if (temp == NULL)
            {
                ans.push_back(sm);
                sm.clear();
                if (!q.empty())
                    q.push(NULL);
            }
            else
            {
                sm.push_back(temp->val);
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
        }

        return ans;
    }

    vector<vector<int>> levelOrder2(TreeNode *root)
    { // without NUll , optimal
        vector<vector<int>> ans;
        if (!root)
            return ans;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            vector<int> level;

            for (int i = 0; i < size; ++i)
            {
                TreeNode *node = q.front();
                q.pop();
                level.push_back(node->val);

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            ans.push_back(level);
        }

        return ans;
    }
};

int main()
{
    // Sample binary tree:
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2, new TreeNode(4), new TreeNode(5));
    root->right = new TreeNode(3);

    Solution sol;
    vector<vector<int>> result = sol.levelOrder(root);

    // Print the result
    cout << "Level-order Traversal:\n";
    for (const auto &level : result)
    {
        for (int val : level)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
