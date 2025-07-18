#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
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
{ // recursion
public:
    void traverse(TreeNode *root, vector<int> &data)
    {
        if (root == NULL)
            return;
        data.push_back(root->val);
        traverse(root->left, data);
        traverse(root->right, data);
    }

    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> data;
        traverse(root, data);
        return data;
    }
}; // in preorder we first trtaverse root ->left -> right

int main()
{
    //     1
    //    / \
    //   2   3
    //      /
    //     4

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);

    Solution sol;
    vector<int> result = sol.preorderTraversal(root);

    cout << "Preorder Traversal: ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    // Clean up (free memory)
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}
