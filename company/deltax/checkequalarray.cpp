//gfg 
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // Function to check if two arrays are equal in terms of frequency of each element.
    bool checkEqual(vector<int>& a, vector<int>& b) {
        // Quick check: arrays must be of the same size
        if (a.size() != b.size()) return false;

        // Store frequencies of elements from array 'a'
        unordered_map<int, int> mapi;
        for (int i = 0; i < a.size(); ++i) {
            mapi[a[i]]++;
        }

        // Compare frequencies with elements from array 'b'
        for (int i = 0; i < b.size(); ++i) {
            // If b[i] not found in map or its count is zero, arrays aren't equal
            if (mapi.find(b[i]) == mapi.end()) {
                return false;
            }
            mapi[b[i]]--;
            if (mapi[b[i]] == 0) {
                mapi.erase(b[i]);
            }
        }

        // If map is empty now, arrays matched perfectly
        return mapi.empty();
    }
};

int main() {
    Solution sol;
    vector<int> a = {1, 2, 5, 4, 0};
    vector<int> b = {2, 4, 5, 0, 1};

    bool result = sol.checkEqual(a, b);
    cout << (result ? "true" : "false") << endl;
    return 0;
}

/*
🔍 Time Complexity: O(n)
    - Building frequency map for array 'a' takes O(n)
    - Comparing with elements of array 'b' takes O(n)
    - Overall: linear in terms of array size

🔍 Space Complexity: O(n)
    - In worst case, all elements in 'a' are distinct => O(n) space used for map

📌 Notes:
    - This checks for element counts rather than order.
    - Efficient for large arrays due to hash map lookups being nearly constant time.
*/
