#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

// Definition for a Binary Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

class Solution
{
public:
    // Time: O(N log N) | Space: O(N)
    // Level-order traversal where latest node at each horizontal distance is stored (bottom view).
    vector<int> bottomView(Node *root)
    {
        queue<pair<Node *, int>> q;
        map<int, int> map;
        q.push({root, 0});
        map[0] = root->data;
        vector<int> ans;

        while (!q.empty())
        {
            int size = q.size();

            for (int i = 0; i < size; ++i)
            {
                Node *temp = q.front().first;
                int hd = q.front().second;

                // Always update map[hd] so that the last node (bottom-most) at that HD remains
                map[hd] = temp->data;

                if (temp->left)
                {
                    q.push({temp->left, hd - 1});
                }
                if (temp->right)
                {
                    q.push({temp->right, hd + 1});
                }
                q.pop();
            }
        }

        for (auto &it : map)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};

// Sample driver code
int main()
{
    /*
         20
        /  \
      8     22
     / \      \
    5   3      25
       / \
      10 14
    */
    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(5);
    root->left->right = new Node(3);
    root->right->right = new Node(25);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);

    Solution obj;
    vector<int> result = obj.bottomView(root);

    cout << "Bottom view: ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
