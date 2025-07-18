#include <iostream>
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
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;

        queue<TreeNode *> q;
        q.push(root);
        int num = 0;

        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *temp = q.front();
                q.pop();
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
            num++;
        }
        return num;
    }
};

int main()
{
    // Sample tree:
    //       1
    //      / \
    //     2   3
    //    /
    //   4
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2, new TreeNode(4), nullptr);
    root->right = new TreeNode(3);

    Solution sol;
    int depth = sol.maxDepth(root);
    cout << "Max Depth: " << depth << endl;

    return 0;
}
