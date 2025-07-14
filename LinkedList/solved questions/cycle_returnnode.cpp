// linked list cycle 2 , LEetcode 142
#include <iostream>
#include <unordered_set>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    // ListNode *detectCyclee(ListNode *head)
    // { // not optimal uses extra space
    //     unordered_set<ListNode *> x;
    //     ListNode *temp = head;
    //     while (temp)
    //     {
    //         x.insert(temp);
    //         temp = temp->next;
    //         if (x.contains(temp))
    //         {
    //             return temp;
    //         }
    //     }
    //     return temp;
    // }

    ListNode *detectCycle(ListNode *head) // optimal time O(n),
    {
        if (head == nullptr || head->next == nullptr)
            return nullptr;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                break;
        }

        if (slow != fast)
            return nullptr;

        ListNode *start = head;
        while (start != slow)
        {
            start = start->next;
            slow = slow->next;
        }
        return start;
    }
};

// Helper to create a cycle in the linked list
ListNode *createListWithCycle()
{
    ListNode *head = new ListNode(3);
    ListNode *node2 = new ListNode(2);
    ListNode *node0 = new ListNode(0);
    ListNode *node4 = new ListNode(-4);

    head->next = node2;
    node2->next = node0;
    node0->next = node4;
    node4->next = node2; // Creates a cycle at node2

    return head;
}

int main()
{
    Solution sol;
    ListNode *head = createListWithCycle();

    ListNode *cycleNode = sol.detectCycle(head);
    if (cycleNode)
    {
        cout << "Cycle starts at node with value: " << cycleNode->val << endl;
    }
    else
    {
        cout << "No cycle detected." << endl;
    }

    return 0;
}
