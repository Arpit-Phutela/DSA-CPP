// LeetCode 57 - Insert Interval
// Approach: Insert + Merge Intervals
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        // Stores the intervals after inserting the new interval
        vector<vector<int>> ans;

        int start_new = newInterval[0];
        int end_new = newInterval[1];

        // Flag to check whether the new interval has been inserted
        bool insert = false;

        // Insert the new interval at its correct position
        for(int i = 0; i < intervals.size(); i++) {

            int start = intervals[i][0];

            // Insert the new interval before the current interval
            if(start >= start_new && insert == false) {

                ans.push_back({start_new, end_new});
                insert = true;
            }

            // Add the current interval
            ans.push_back(intervals[i]);
        }

        // If the new interval belongs at the end
        if(!insert) {
            ans.push_back(newInterval);
        }

        // Merge the intervals
        vector<vector<int>> merge;

        // Initialize the first interval
        int start1 = ans[0][0];
        int end1 = ans[0][1];

        for(int i = 0; i < ans.size(); i++) {

            int start2 = ans[i][0];
            int end2 = ans[i][1];

            // Overlapping intervals
            if(end1 >= start2) {

                // Starting point remains unchanged
                start1 = start1;

                // Extend the ending point
                end1 = max(end1, end2);

                continue;
            }

            // Store the merged interval
            merge.push_back({start1, end1});

            // Start a new interval
            start1 = start2;
            end1 = end2;
        }

        // Store the last merged interval
        merge.push_back({start1, end1});

        return merge;
    }
};
