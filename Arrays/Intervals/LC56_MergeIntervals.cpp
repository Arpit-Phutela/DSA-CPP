// LeetCode 56 - Merge Intervals
// Approach: Sorting + Greedy
// Time Complexity: O(n log n)
// Space Complexity: O(n)

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        // Stores the merged intervals
        vector<vector<int>> ans;

        // Sort intervals based on starting time
        sort(intervals.begin(), intervals.end());

        // Initialize the first interval
        int start1 = intervals[0][0];
        int end1 = intervals[0][1];

        for(int i = 0; i < intervals.size(); i++) {

            // Current interval
            int start2 = intervals[i][0];
            int end2 = intervals[i][1];

            // If the intervals overlap,
            // merge them by extending the ending point
            if(end1 >= start2) {

                // Starting point remains unchanged
                start1 = start1;

                // Update the ending point
                end1 = max(end1, end2);

                continue;
            }

            // No overlap, store the previous merged interval
            ans.push_back({start1, end1});

            // Start a new interval
            start1 = start2;
            end1 = end2;
        }

        // Store the last merged interval
        ans.push_back({start1, end1});

        return ans;
    }
};
