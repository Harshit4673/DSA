// leetcode 237
//  given the node has to removed from the ll , node can't be the last element , head's not given

struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

// in this we just copy the value of next node to it and then delete the next node
class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        node->val = node->next->val;
        ListNode *temp = node->next;
        node->next = node->next->next;
        delete temp;
        return;
    }
};