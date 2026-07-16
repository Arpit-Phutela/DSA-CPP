// GFG - Minimum Meeting Rooms
// Approach: Sorting + Two Pointers (Line Sweep)
// Time Complexity: O(n log n)
// Space Complexity: O(1)

class Solution {
public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {

        // Sort the start and end times separately
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        // Pointers for start and end arrays
        int i = 0;
        int j = 0;

        // Current rooms occupied
        int rooms = 0;

        // Maximum rooms required at any time
        int maxRooms = 0;

        while(i < start.size() && j < end.size()) {

            // A new meeting starts before the earliest meeting ends
            if(start[i] < end[j]) {

                rooms++;

                maxRooms = max(maxRooms, rooms);

                i++;
            }
            else {

                // A meeting has ended, free one room
                rooms--;

                j++;
            }
        }

        return maxRooms;
    }
};
