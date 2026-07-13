// LeetCode 986 - Interval List Intersections
// Approach: Two Pointers
// Time Complexity: O(n + m)
// Space Complexity: O(1) (excluding the output array)

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {

        // Stores all the intersecting intervals
        vector<vector<int>> ans;

        // Pointers for both interval lists
        int i = 0;
        int j = 0;

        while(i < firstList.size() && j < secondList.size()) {

            // Current interval from first list
            int start1 = firstList[i][0];
            int end1 = firstList[i][1];

            // Current interval from second list
            int start2 = secondList[j][0];
            int end2 = secondList[j][1];

            // If the first interval starts earlier
            if(start1 <= start2) {

                // Check whether the intervals overlap
                if(end1 >= start2) {

                    // Find the common intersection
                    int s = max(start1, start2);
                    int e = min(end1, end2);

                    ans.push_back({s, e});
                }
            }
            // If the second interval starts earlier
            else {

                // Check whether the intervals overlap
                if(end2 >= start1) {

                    // Find the common intersection
                    int s = max(start1, start2);
                    int e = min(end1, end2);

                    ans.push_back({s, e});
                }
            }

            // Move the pointer whose interval ends first
            if(end1 <= end2)
                i++;
            else
                j++;
        }

        return ans;
    }
};
