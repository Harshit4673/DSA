#include <iostream>
#include <unordered_map>
using namespace std;

// #leetcode 141

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    bool hasCycle(ListNode *head) // optimal
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
};
// Floyd’s Cycle Detection Algorithm — aka Tortoise and Hare — is a classic and super-efficient way to detect cycles in a linked list using two pointers
// complexitiy o(n) , no space ,

// ----------------------------------------------------------------
// ----------------------------------------------------------------

// not optimal with extra space time and space O(n)
bool hasCycle(ListNode *head)
{
    unordered_map<ListNode *, int> res;
    ListNode *temp = head;
    while (temp)
    {
        res[temp]++;
        if (res[temp] == 2)
            return true;
        temp = temp->next;
    }
    return false;
}

// 🔁 Main driver to test
int main()
{
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    node1->next = node2;
    node2->next = node3;
    // Uncomment for cycle test:
    // node3->next = node1;

    Solution sol;
    cout << "Optimal: " << sol.hasCycle(node1) << endl;
    cout << "Hash map: " << hasCycle(node1) << endl;

    return 0;
}
