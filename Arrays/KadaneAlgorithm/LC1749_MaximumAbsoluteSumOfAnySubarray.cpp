// LeetCode 1749 - Maximum Absolute Sum of Any Subarray
// Approach: Kadane's Algorithm (Maximum & Minimum Subarray Sum)
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {

        // Stores the maximum absolute subarray sum found so far
        int ans = nums[0];

        // Maximum subarray sum ending at the current index
        int max_prev = nums[0];

        // Minimum subarray sum ending at the current index
        int min_prev = nums[0];

        for(int i = 1; i < nums.size(); i++) {

            // Start a new subarray from the current element
            int c1 = nums[i];

            // Extend the previous maximum subarray
            int c2 = nums[i] + max_prev;

            // Extend the previous minimum subarray
            int c3 = nums[i] + min_prev;

            // Best maximum subarray ending here
            max_prev = max(c1, c2);

            // Best minimum subarray ending here
            min_prev = min(c1, c3);

            // Update the answer using both maximum
            // and absolute value of minimum subarray sums
            ans = max(ans, max(max_prev, abs(min_prev)));
        }

        return abs(ans);
    }
};
