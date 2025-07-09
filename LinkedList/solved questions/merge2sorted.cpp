#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Helper function to create a linked list from array
ListNode *createList(int arr[], int n)
{
    if (n == 0)
        return nullptr;
    ListNode *head = new ListNode(arr[0]);
    ListNode *curr = head;
    for (int i = 1; i < n; ++i)
    {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

// Helper function to print a linked list
void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

class Solution
{
public:
    ListNode *mergeTwoListss(ListNode *l1, ListNode *l2)
    { // secondary method , same complexity
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        if (l1->val > l2->val)
        {
            swap(l1, l2);
        }
        ListNode *res = l1;

        while (l1 && l2)
        {
            ListNode *temp = NULL;
            while (l1 && l2->val >= l1->val)
            {
                temp = l1;
                l1 = l1->next;
            }
            temp->next = l2;

            swap(l1, l2);
        }
        return res;
    }

    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) // time O(m+n) , space O(1)
    {
        ListNode dummy;
        ListNode *tail = &dummy;

        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                tail->next = list1;
                list1 = list1->next;
            }
            else
            {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        tail->next = list1 ? list1 : list2;
        return dummy.next;
    }
};

// main goal is to not take extra space
 
int main()
{
    Solution sol;

    int arr1[] = {1, 2, 4};
    int arr2[] = {1, 3, 4};
    ListNode *list1 = createList(arr1, 3);
    ListNode *list2 = createList(arr2, 3);

    ListNode *merged = sol.mergeTwoListss(list1, list2);
    printList(merged);

    return 0;
}
