#include <iostream>
#include <vector>
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
    void traverse(TreeNode *root, vector<int> &ans)  // time O(n)and spaceo(n)
    {
        if (root == NULL)
            return;
        traverse(root->left, ans);
        ans.push_back(root->val); // root is already not NULL
        traverse(root->right, ans);
    }

    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        traverse(root, ans);
        return ans;
    }
};


//morris traversal  - optimal , time - (O(n) approx, O(n)+O(n)) , space - O(1)
vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> res;
    TreeNode *curr = root;
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            res.push_back(curr->val);
            curr = curr->right;
        }
        else
        {
            TreeNode *prev = curr->left;
            while (prev->right && prev->right != curr)
            {
                prev = prev->right;
            }
            if (prev->right == NULL)
            {
                prev->right = curr;
                curr = curr->left;
            }
            else
            {
                prev->right = NULL;
                res.push_back(curr->val);
                curr = curr->right;
            }
        }
    }
    return res;
}

int main()
{
    // Create sample binary tree:
    //        1
    //         \
    //          2
    //         /
    //        3
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution sol;
    vector<int> result = sol.inorderTraversal(root);

    // Print result
    cout << "Inorder Traversal: ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
