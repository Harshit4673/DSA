// leetcode 455
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        // Sort the greed factor array and cookie size array
        sort(g.begin(), g.end()); // O(n log n), where n = number of children
        sort(s.begin(), s.end()); // O(m log m), where m = number of cookies

        int i = 0, j = 0, cnt = 0;

        // Assign cookies using two-pointer technique
        while (i < g.size() && j < s.size())
        { // O(n + m)
            if (s[j] >= g[i])
            {
                cnt++; // Child i is content
                i++;   // Move to next child
            }
            j++; // Move to next cookie
        }

        return cnt;
    }

    /*
    Time Complexity:
    - Sorting g: O(n log n)
    - Sorting s: O(m log m)
    - Two-pointer loop: O(n + m)
    => Total: O(n log n + m log m)

    Space Complexity:
    - O(1) auxiliary space (in-place sorting, ignoring recursion stack)
    */
};

int main()
{
    Solution sol;

    vector<int> g = {1, 2, 3}; // Greed factors
    vector<int> s = {1, 1};    // Cookie sizes

    int result = sol.findContentChildren(g, s);
    cout << "Max number of content children: " << result << endl;

    return 0;
}
