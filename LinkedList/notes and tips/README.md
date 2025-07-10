🧠 **Linked List Concepts & Tricks**  
- Use slow and fast pointers for detecting cycles or finding middle nodes.  
- Dummy head nodes simplify edge case handling (insert/delete at head).  
- Always consider null checks before accessing `next` or `prev`.  
- Reversing a linked list is a common subroutine (iterative or recursive).  
- Be cautious of memory leaks—delete unused nodes in languages like C++.  
- Convert between array and linked list for testing.  
- Track previous, current, and next nodes for modifications.  
- Use stack for reverse traversal or comparison (e.g., palindrome check).  
- Prefer singly linked list unless you need backward traversal.  

🛠️ **Common Linked List Operations**  
- Insert at head → O(1)  
- Insert at tail → O(1) if tail pointer exists, O(n) otherwise  
- Delete a node by value → O(n)  
- Reverse list (iterative)  
- Find middle node → slow and fast pointer technique  
- Detect cycle → Floyd’s Cycle Detection (Tortoise & Hare)  
- Merge two sorted lists → Two-pointer approach  
- Find intersection of two lists → length difference + same traversal  
- Remove N-th node from end → Two-pointer with gap of N  

🧮 **Time & Space Complexity**  
- Access: O(n) (unlike arrays, no random access)  
- Search: O(n)  
- Insert/Delete at head: O(1)  
- Insert/Delete at tail: O(n) (if no tail pointer)  
- Reversal: O(n)  
- Cycle detection: O(n), Space: O(1)  

🔁 **1. Reverse a Linked List**  
- Use three pointers: `prev`, `curr`, `next`.  
- Iteratively update `curr->next = prev`.  
- Set `prev` as new head.  
- Time: O(n), Space: O(1).  

🔗 **2. Detect Cycle in Linked List**  
- Use Floyd’s Cycle Detection (slow/fast pointer).  
- If they meet, cycle exists.  
- To find entry point: reset one pointer to head, move both one step at a time.  
- Time: O(n), Space: O(1).  

🔄 **3. Merge Two Sorted Linked Lists**  
- Use dummy node and two pointers.  
- Append the smaller node to result.  
- Attach remaining part of longer list.  
- Time: O(n + m), Space: O(1) if done in-place.  

🧮 **4. Find Middle Node**  
- Use slow and fast pointers.  
- Fast moves 2x faster than slow.  
- When fast reaches end, slow is at middle.  
- Time: O(n), Space: O(1).  

📥 **5. Remove N-th Node from End**  
- Use two pointers with N-step gap.  
- When fast reaches end, slow is just before the target node.  
- Delete `slow->next`.  
- Time: O(n), Space: O(1).  

🔁 **6. Check if Linked List is Palindrome**  
- Find middle node using slow/fast pointer.  
- Reverse second half of list.  
- Compare both halves.  
- Optional: Restore list after check.  
- Time: O(n), Space: O(1).  

➕ **7. Add Two Numbers Represented by Linked Lists**  
- Traverse both lists and sum values + carry.  
- Create new nodes for result list.  
- Continue till all nodes and carry are processed.  
- Time: O(max(n, m)), Space: O(max(n, m)).  

📦 **8. Intersection Point of Two Lists**  
- Get lengths of both lists.  
- Move pointer of longer list ahead by length difference.  
- Traverse both together until they meet.  
- Time: O(n + m), Space: O(1).  

🔄 **9. Flatten a Linked List (multi-level)**  
- Use recursion or stack to flatten next and child pointers.  
- Handle in-place if possible.  
- Time: O(n), Space: O(n) (stack or recursion depth).  

🧹 **10. Delete a Given Node (Without Head Reference)**  
- Copy next node’s data to current.  
- Delete `curr->next`.  
- Only works if node is not tail.  
- Time: O(1), Space: O(1).  
