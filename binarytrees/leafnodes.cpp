#include <iostream>
using namespace std;

// Definition for a binary tree node
struct Node
{
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    void traverse(Node *root, int &num)
    {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL)
        {
            num++;
            return;
        }
        traverse(root->left, num);
        traverse(root->right, num);
    }

    int countLeaves(Node *root)
    {
        int num = 0;
        traverse(root, num);
        return num;
    }
};

int main()
{
    // Sample tree:
    //        1
    //       / \
    //      2   3
    //         / \
    //        4   5
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);

    Solution sol;
    int leafCount = sol.countLeaves(root);
    cout << "Number of leaf nodes: " << leafCount << endl;

    return 0;
}
