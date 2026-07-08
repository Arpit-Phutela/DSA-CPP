// LeetCode 53 - Maximum Subarray
// Approach: Kadane's Algorithm
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        // Stores the maximum subarray sum found so far
        int ans = nums[0];

        // Stores the maximum subarray sum ending at the current index
        int best_prev = nums[0];

        for(int i = 1; i < nums.size(); i++) {

            // Extend the previous subarray
            best_prev = best_prev + nums[i];

            // Or start a new subarray from the current element
            best_prev = max(nums[i], best_prev);

            // Update the overall maximum subarray sum
            ans = max(best_prev, ans);
        }

        return ans;
    }
};
