#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        int total = n * (n + 1) / 2; // Sum of first n natural numbers
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += nums[i]; // Calculating sum of array elements
        }
        return total - ans; // The difference gives the missing number
    }

    /*
    Time Complexity: O(n)
    - Loop through the array once to compute the sum.

    Space Complexity: O(1)
    - Uses only constant extra space.
    */
};

int main()
{
    Solution sol;
    vector<int> nums = {3, 0, 1}; // Example input
    int result = sol.missingNumber(nums);
    cout << "Missing number is: " << result << endl; // Output should be 2
    return 0;
}
