// count inversions gfg
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // Merge function that counts inversions while sorting the subarrays
    void merge(vector<int> &nums, int mid, int low, int high, int &cnt)
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
                cnt += mid - left + 1; // All remaining left elements form an inversion
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

    // Recursive Merge Sort with inversion counting
    void mergeSort(vector<int> &arr, int low, int high, int &cnt)
    {
        if (low >= high)
            return;

        int mid = (low + high) / 2;
        mergeSort(arr, low, mid, cnt);
        mergeSort(arr, mid + 1, high, cnt);
        merge(arr, mid, low, high, cnt);
    }

    // Main function to return inversion count
    int inversionCount(vector<int> &arr)
    {
        int cnt = 0;
        mergeSort(arr, 0, arr.size() - 1, cnt);
        return cnt;
    }

    /*
    Time Complexity: O(n log n)
    - Merge Sort divides the array log n times and merges in linear time.

    Space Complexity: O(n)
    - Temporary vector used for merging takes linear space.
    */
};

int main()
{
    Solution sol;
    vector<int> arr = {8, 4, 2, 1}; // Example input
    int result = sol.inversionCount(arr);
    cout << "Inversion Count: " << result << endl; // Output: 6
    return 0;
}
