#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // Merges nums2 into nums1 assuming nums1 has enough trailing space
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1;     // Last index of valid elements in nums1
        int j = n - 1;     // Last index of nums2
        int k = m + n - 1; // Last index of merged array

        while (j >= 0)
        {
            if (i >= 0 && nums1[i] > nums2[j])
            {
                nums1[k--] = nums1[i--];
            }
            else
            {
                nums1[k--] = nums2[j--];
            }
        }
    }

    /*
    Time Complexity: O(m + n)
    - Each element is considered once from both arrays during the merge.

    Space Complexity: O(1)
    - Merging is done in-place without using any extra array.
    */
};

int main()
{
    Solution sol;
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    int m = 3, n = 3;

    sol.merge(nums1, m, nums2, n);

    cout << "Merged Array: ";
    for (int num : nums1)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
