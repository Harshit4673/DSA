#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// ==============================
// METHOD 1: Simulated Min Heap using Max Heap (by pushing negative values)
// Time Complexity: O(n log k)
// Space Complexity: O(k)
// Explanation:
// - We simulate a min-heap by pushing -nums[i] to a max heap
// - This keeps the k largest elements with a max-heap interface
// ==============================
class SolutionNegHeap
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int> q; // max heap of negative numbers

        // Initialize heap with first k elements (negated)
        for (int i = 0; i < k; ++i)
        {
            q.push(-nums[i]);
        }

        // Process the rest of the array
        for (size_t i = k; i < nums.size(); ++i)
        {
            // If current number is bigger than min in heap (-q.top())
            if (-nums[i] > q.top())
            {
                q.pop();
                q.push(-nums[i]);
            }
        }

        // Return negative of top (restore original value)
        return -q.top();
    }
};

// ==============================
// METHOD 2: Min Heap Using STL comparator
// Time Complexity: O(n log k)
// Space Complexity: O(k)
// Explanation:
// - Maintains a min-heap of size k
// - Top of the heap always gives the kth largest once all elements are processed
// ==============================
class SolutionMinHeap
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int num : nums)
        {
            minHeap.push(num);
            if (minHeap.size() > k)
            {
                minHeap.pop(); // Remove smallest if size > k
            }
        }

        return minHeap.top(); // kth largest will be on top
    }
};

// ==============================
// METHOD 3: Quickselect (Hoare’s Partition Algorithm)
// Average Time Complexity: O(n)
// Worst-case Time: O(n^2)
// Space Complexity: O(1)
// Explanation:
// - Uses partition logic like quicksort
// - Finds the kth largest without fully sorting the array
// ==============================
class SolutionQuickselect
{
public:
    // Partition the array like in quicksort
    int partition(vector<int> &nums, int left, int right)
    {
        int pivot = nums[left];
        int i = left + 1;
        int j = right;

        while (i <= j)
        {
            if (nums[i] < pivot && nums[j] > pivot)
            {
                swap(nums[i++], nums[j--]);
            }
            if (nums[i] >= pivot)
                ++i;
            if (nums[j] <= pivot)
                --j;
        }

        swap(nums[left], nums[j]);
        return j;
    }

    int findKthLargest(vector<int> &nums, int k)
    {
        int left = 0, right = nums.size() - 1;
        int indexToFind = k - 1;

        while (left <= right)
        {
            int pivotIndex = partition(nums, left, right);
            if (pivotIndex == indexToFind)
            {
                return nums[pivotIndex];
            }
            else if (pivotIndex < indexToFind)
            {
                left = pivotIndex + 1;
            }
            else
            {
                right = pivotIndex - 1;
            }
        }
        return -1; // Should never reach here
    }
};

// ==============================
// MAIN FUNCTION (For Visual Studio or CLI Testing)
// ==============================
int main()
{
    vector<int> nums1 = {3, 2, 1, 5, 6, 4}; // Sample Input
    vector<int> nums2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k1 = 2;
    int k2 = 4;

    // Test Using Simulated Min Heap (NegHeap)
    SolutionNegHeap sol1;
    cout << "[NegHeap] Kth Largest: " << sol1.findKthLargest(nums1, k1) << endl; // Output: 5

    // Test Using STL Min Heap
    SolutionMinHeap sol2;
    cout << "[MinHeap] Kth Largest: " << sol2.findKthLargest(nums2, k2) << endl; // Output: 4

    // Test Using Quickselect
    SolutionQuickselect sol3;
    cout << "[Quickselect] Kth Largest: " << sol3.findKthLargest(nums1, k1) << endl; // Output: 5

    return 0;
}
