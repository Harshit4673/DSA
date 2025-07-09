🔁 1. Reverse a LinkedList
Use 3 pointers: prev, curr, and next to safely reverse links.
Iterate till null: Stop when curr == nullptr.
Initialize prev as null: It will become the new tail.
Edge Case: Handle empty list or a single node.
In-place reversal: Don’t use extra space unless explicitly allowed.

🎯 2. Find the Middle of LinkedList
Use slow and fast pointers: Slow moves 1 step, fast moves 2 steps.
When fast reaches end: Slow is at the middle.
Even nodes: Decide whether to return the first or second middle.
Avoid counting: Don’t loop twice—two-pointer method is optimal.
Check nulls: Always handle null head or single node case.

🔀 3. Merge Two Sorted LinkedLists
Use dummy node: Helps build the result list smoothly.
Compare node values: Attach smaller one and move its pointer.
Handle remaining nodes: Only one list may still have nodes.
No new nodes: Reuse existing nodes unless stated otherwise.
Recursive or Iterative: Know both methods; recursion is elegant, iteration is memory-safe.

📦 4. Remove N-th Node from End
Two-pointer technique: Keep a gap of n between two pointers.
Use dummy node: Helps in deleting the head node easily.
Edge case: If n == length, you’re deleting the head.
Move fast n steps: Then move both till fast reaches end.
Delete carefully: Adjust prev->next = prev->next->next.

➕ 5. Add Two Numbers as LinkedList
Use dummy node: For clean list construction.
Simulate digit-by-digit addition: Start from least significant digit.
Handle carry: Add carry to next node's sum.
Different lengths: Pad with zeroes or handle null as zero.
Carry at end: Don’t forget to add final carry if exists.

❌ 6. Delete Given Node (O(1) Solution)
Copy next node’s value: Replace current node's value.
Delete next node: node->next = node->next->next
Cannot delete last node: This method fails for the tail.
No access to previous: That’s why we overwrite current.
Don't use head: This solution only works when node to delete is not the last.
