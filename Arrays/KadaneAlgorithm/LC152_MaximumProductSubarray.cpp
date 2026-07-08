// LeetCode 152 - Maximum Product Subarray
// Approach: Kadane's Algorithm (Tracking Maximum & Minimum Product)
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxProduct(vector<int>& nums) {

        // Stores the maximum product found so far
        int ans = nums[0];

        // Stores the maximum product ending at the current index
        int max_prev = nums[0];

        // Stores the minimum product ending at the current index
        // (needed because a negative number can become the maximum)
        int min_prev = nums[0];

        for(int i = 1; i < nums.size(); i++)
        {
            // Option 1: Start a new subarray
            int c1 = nums[i];

            // Option 2: Extend previous minimum product subarray
            int c2 = min_prev * nums[i];

            // Option 3: Extend previous maximum product subarray
            int c3 = max_prev * nums[i];

            // Maximum product ending at current index
            max_prev = max(c1, max(c2, c3));

            // Minimum product ending at current index
            min_prev = min(c1, min(c2, c3));

            // Update the overall maximum product
            ans = max(ans, max(max_prev, min_prev));
        }

        return ans;
    }
};
