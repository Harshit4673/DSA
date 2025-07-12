🧱 Stack – LIFO (Last In First Out)

1. Use Cases: Undo feature, Balanced parentheses, Reverse string, DFS, Next Greater Element, Histogram area.
2. Basic Operations: push(), pop(), top(), isEmpty().
3. Valid Parentheses: Use a stack to push opening brackets and pop when closing matches.
4. Next Greater Element: Traverse from right, use stack to store candidates.
5. Monotonic Stack: For problems involving min/max in ranges (e.g., stock span, temperature).
   ⏱️ Time Complexities: Push/Pop/Top – O(1). Great for Backtracking, Expression Evaluation.

🚋 Queue – FIFO (First In First Out)

1. Use Cases: BFS, Scheduling, Producer-Consumer, Caching, Sliding Window Max.
2. Basic Operations: enqueue(), dequeue(), peek(), isEmpty().
3. Circular Queue: Avoids wasted space; use modulo for indexing.
4. Deque (Double-Ended Queue): For sliding window problems (max/min in window).
5. Priority Queue / Heap: When elements need to be processed based on priority.
   ⏱️ Time Complexities: Enqueue/Dequeue – O(1), Deque with deque – O(1) both ends.

🔄 Common Tips

1. Stack: Best for reversal problems or nested structures.
2. Queue: Best for level-order traversal or sequential task processing.
3. Use deque for sliding window max/min in O(n).
4. Master Queue using 2 Stacks & Stack using 2 Queues (frequent interview pattern).
