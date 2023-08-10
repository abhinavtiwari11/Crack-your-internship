//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
     static bool comparator(pair<int, int> &a, pair<int, int> &b){
        return a.second < b.second;
    }
    
    // Function to find the maximum number of meetings that can be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int, int>> meetings;
        for(int i=0; i<n; i++)
            meetings.push_back(make_pair(start[i], end[i]));
        
        // Sorting meetings in increasing order of their finish time
        sort(meetings.begin(), meetings.end(), comparator);

        // The first meeting always gets executed, count starts from 1
        int count = 1;
        int prevtime = meetings[0].second;

        for(int i = 1; i < n; i++)
        {
            // If this meeting can fit in the current schedule.
            if(meetings[i].first > prevtime)
            {
                // Increment count of meetings and update end time.
                count++;
                prevtime = meetings[i].second;
            }
        }

        // Return final count of meetings.
        return count;
    }
};
            

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends