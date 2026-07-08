// LeetCode 1186 - Maximum Subarray Sum with One Deletion
// Approach: Kadane's Algorithm + Dynamic Programming
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maximumSum(vector<int>& arr) {

        // Stores the maximum subarray sum found so far
        int ans = arr[0];

        // Maximum subarray sum ending at current index
        // without using any deletion
        int no_del = arr[0];

        // Maximum subarray sum ending at current index
        // after using exactly one deletion
        int del_used = arr[0];

        for(int i = 1; i < arr.size(); i++) {

            // Start a new subarray from current element
            int c1 = arr[i];

            // Extend previous subarray without deletion
            int c2 = arr[i] + no_del;

            // Extend previous subarray after deletion has already been used
            int c3 = arr[i] + del_used;

            // Delete the current element
            // so answer becomes previous no-deletion value
            int c4 = no_del;

            // Best sum ending here without deletion
            no_del = max(c1, c2);

            // Best sum ending here after one deletion
            del_used = max(c3, c4);

            // Update overall maximum answer
            ans = max(ans, max(c1, max(c2, max(c3, c4))));
        }

        return ans;
    }
};
