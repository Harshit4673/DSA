//leetcode 160
// #intersection of two linked list
// search in hash takes O (1)avg and O(n) in worst
#include <iostream>
#include <unordered_set>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// first we use extra space o(m)
// we use set as map takes two values .
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *a = headA;
        ListNode *b = headB;
        unordered_set<ListNode *> map;
        while (a)
        {
            map.insert(a);
            a = a->next;
        }
        while (b)
        {
            if (map.count(b))
                return b;
            b = b->next;
        }
        return NULL;
    }

    // second best optimal is to find length of both first , then find the difference of them , and then move the start point by the difference in shorterlength list and then start comparing , to find length max(m,n), then difference (m-n) and to compare min (m,n); this is time complexity, and space is o(1)

    // final optimal , cleanest code and best for the interview and shit
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *a = headA;
        ListNode *b = headB;
        while (a != b)
        {
            a = a == NULL ? headB : a->next;
            b = b == NULL ? headA : b->next;
        }
        return a;
    }
};
