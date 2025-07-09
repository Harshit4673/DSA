#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int repeatedStringMatch(string a, string b) // this solution is optimal if we use kmp to find as it offers O(m+n) always 
    {                                           // but in this i used find , whose avg is m+n but worst is m.n 
        int ans = 1;
        string temp = a;
        while (temp.size() < b.size())
        {
            temp += a;
            ans++;
        }
        if (temp.find(b) != string::npos)
        {
            return ans;
        }
        temp += a;
        ans++;
        if (temp.find(b) != string::npos)
        {
            return ans;
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    string a = "abcd";
    string b = "cdabcdab";
    cout << "Minimum repeats: " << sol.repeatedStringMatch(a, b) << endl;
    return 0;
}
