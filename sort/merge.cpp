// leetcode912
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // Merge two sorted halves
    void merge(vector<int> &nums, int mid, int low, int high)
    {
        vector<int> temp(high - low + 1);
        int left = low;
        int right = mid + 1;
        int i = 0;

        while (left <= mid && right <= high)
        {
            if (nums[left] <= nums[right])
            {
                temp[i++] = nums[left++];
            }
            else
            {
                temp[i++] = nums[right++];
            }
        }

        while (left <= mid)
        {
            temp[i++] = nums[left++];
        }

        while (right <= high)
        {
            temp[i++] = nums[right++];
        }

        for (int j = 0; j < temp.size(); ++j)
        {
            nums[low + j] = temp[j];
        }
    }

    // Recursive merge sort function
    void mergeSort(vector<int> &arr, int low, int high)
    {
        if (low >= high)
            return;

        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, mid, low, high);
    }

    // Sorts the input array using merge sort
    vector<int> sortArray(vector<int> &nums)
    {
        int n = nums.size();
        mergeSort(nums, 0, n - 1);
        return nums;
    }

    /*
    Time Complexity: O(n log n)
    - The array is divided log n times and each merge takes O(n) time.

    Space Complexity: O(n)
    - A temporary array is used in every merge step, leading to O(n) space usage.
    */
};

int main()
{
    Solution sol;
    vector<int> nums = {5, 2, 3, 1}; // Example input
    vector<int> sorted = sol.sortArray(nums);

    cout << "Sorted Array: ";
    for (int num : sorted)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
