// #n meetings in one room , questoin on gfg
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int> &start, vector<int> &end)
    {
        vector<pair<int, int>> meetings;

        // Pair up start and end times for meetings
        for (int i = 0; i < start.size(); ++i)
        {
            meetings.push_back({start[i], end[i]});
        }

        // Sort meetings by their end times (Greedy Approach)
        sort(meetings.begin(), meetings.end(), [](const pair<int, int> &a, const pair<int, int> &b)
             { return a.second < b.second; });

        int cnt = 1; // First meeting is always selected
        int freetime = meetings[0].second;

        // Check for non-overlapping meetings
        for (int i = 1; i < start.size(); ++i)
        {
            if (freetime < meetings[i].first)
            {
                cnt++;
                freetime = meetings[i].second;
            }
        }
        return cnt;
    }
};

//-----------------------------------------------------------------------------------------
// in this we can also get the position
// Structure to represent a meeting
struct Meeting
{
    int start;
    int end;
    int pos; // 1-based index
};

int maxMeetings(vector<int> &start, vector<int> &end)
{
    int n = start.size();
    vector<Meeting> meetings;

    // Fill the meetings vector with start, end, and position
    for (int i = 0; i < n; ++i)
    {
        meetings.push_back({start[i], end[i], i + 1});
    }

    // Sort meetings by end time using lambda
    sort(meetings.begin(), meetings.end(), [](const Meeting &a, const Meeting &b)
         {
            if (a.end == b.end)
                return a.pos < b.pos;  // Tie-breaker on position
            return a.end < b.end; });

    int count = 1;
    int lastEnd = meetings[0].end;

    for (int i = 1; i < n; ++i)
    {
        if (meetings[i].start > lastEnd)
        {
            count++;
            lastEnd = meetings[i].end;
        }
    }

    return count;
}
//-------------------------------------------------------------------------------

int main()
{
    Solution sol;
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};

    int maxMeet = sol.maxMeetings(start, end);
    cout << "Maximum number of meetings: " << maxMeet << endl;

    return 0;
}

/*
----------------------------
🧠 Approach (Greedy):
- Pair each meeting's start and end times.
- Sort the meetings by their ending time.
- Always pick the earliest finishing meeting that doesn't overlap.

⏱ Time Complexity:
- O(N log N): For sorting the meetings by end time.
- O(N): For iterating through meetings to count non-overlapping ones.
- Total: O(N log N)

📦 Space Complexity:
- O(N): For storing meeting pairs in a separate vector.
*/
