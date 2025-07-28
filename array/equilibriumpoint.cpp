// gfg
#include <iostream>
#include <vector>
#include <numeric> // for accumulate
using namespace std;

class Solution
{
public:
    int findEquilibrium(vector<int> &arr)
    {
        int n = arr.size();
        int i = 0;
        float total = accumulate(arr.begin(), arr.end(), 0); // Total sum of array
        float sum = 0;

        while (i < n - 1)
        {
            sum += arr[i];
            if (sum == (total - arr[i + 1]) / 2)
            {
                return i + 1; // Found the equilibrium index
            }
            i++;
        }
        return -1; // No equilibrium index found
    }

    /*
    Time Complexity: O(n)
    - Single pass through the array and one accumulate call, both linear.

    Space Complexity: O(1)
    - Constant extra space used regardless of input size.
    */
};

int main()
{
    Solution sol;
    vector<int> arr = {1, 3, 5, 2, 2}; // Example input
    int result = sol.findEquilibrium(arr);
    if (result != -1)
        cout << "Equilibrium Index: " << result << endl;
    else
        cout << "No Equilibrium Index found." << endl;
    return 0;
}
