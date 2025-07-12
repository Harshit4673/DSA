#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//# leetcode 234

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution { // time O(n) - space O(n/2), not optimal
public:
    bool isPalindrome(ListNode* head) {
        stack<int> s;
        ListNode* slow = head;
        ListNode* fast = head;

        // Move fast by 2 steps and slow by 1 step to find the middle
        while(fast != nullptr && fast->next != nullptr){
            s.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }

        // If the list has odd number of nodes, skip the middle node
        if(fast != nullptr) slow = slow->next;

        // Compare second half with stack
        while(slow != nullptr){
            if(s.top() != slow->val) return false;
            s.pop();
            slow = slow->next;
        }

        return true;
    }
};

bool isPalindrome(ListNode* head) { /// optimal O(n) , no space
        if(!head || head->next == nullptr) return true;
        
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast)
            slow = slow->next;

        ListNode* prev = nullptr;
        ListNode* curr = slow;
        ListNode* next = nullptr;

        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        ListNode* temp = head;
        while (prev) {
            if(temp->val != prev->val) return false;
            prev = prev->next;
            temp = temp->next;
        }
        return true;
    }


ListNode* createList(const vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

int main() {
    Solution solution;

    // Example: Palindrome list
    vector<int> values = {1, 2, 2, 1};
    ListNode* head = createList(values);

    if (solution.isPalindrome(head))
        cout << "The list is a palindrome." << endl;
    else
        cout << "The list is not a palindrome." << endl;

    return 0;
}