#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

// Definition of a tree node
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
    // Performs level-order traversal and records the first node at each horizontal distance.
    vector<int> topView(Node *root)
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

                if (map.find(hd) == map.end())
                {
                    map[hd] = temp->data;
                }

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
         1
        / \
       2   3
        \
         4
          \
           5
            \
             6
    */
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->right->right = new Node(5);
    root->left->right->right->right = new Node(6);

    Solution obj;
    vector<int> result = obj.topView(root);

    cout << "Top view: ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
