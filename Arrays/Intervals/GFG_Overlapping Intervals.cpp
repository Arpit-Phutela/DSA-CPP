// GFG - Overlapping Intervals{Check if Intervals Intersect}
// Approach: Sorting + Greedy
// Time Complexity: O(n log n)
// Space Complexity: O(1)

class Solution {
public:

    bool isIntersect(vector<vector<int>> intervals) {

        // Sort intervals according to starting time
        sort(intervals.begin(), intervals.end());

        // Initialize the first interval
        int start1 = intervals[0][0];
        int end1 = intervals[0][1];

        for(int i = 1; i < intervals.size(); i++) {

            // Current interval
            int start2 = intervals[i][0];
            int end2 = intervals[i][1];

            // If the current interval starts before
            // the previous one ends, an intersection exists
            if(end1 >= start2)
                return true;

            // Move to the next interval
            start1 = start2;
            end1 = end2;
        }

        // No overlapping intervals found
        return false;
    }
};
