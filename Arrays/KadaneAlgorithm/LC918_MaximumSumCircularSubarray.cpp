// LeetCode 918 - Maximum Sum Circular Subarray
// Approach: Kadane's Algorithm (Maximum + Minimum Subarray)
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        // Stores the total sum of the array
        int sum = nums[0];

        // Stores the maximum subarray sum found so far
        int ans_max = nums[0];

        // Stores the minimum subarray sum found so far
        int ans_min = nums[0];

        // Maximum subarray sum ending at the current index
        int max_prev = nums[0];

        // Minimum subarray sum ending at the current index
        int min_prev = nums[0];

        for(int i = 1; i < nums.size(); i++)
        {
            // Calculate the total array sum
            sum = sum + nums[i];

            // Start a new maximum subarray
            int c1 = nums[i];

            // Extend the previous maximum subarray
            int c2 = nums[i] + max_prev;

            // Update maximum subarray ending here
            max_prev = max(c1, c2);

            // Update overall maximum subarray sum
            ans_max = max(ans_max, max_prev);

            // Extend the previous minimum subarray
            int c3 = nums[i] + min_prev;

            // Update minimum subarray ending here
            min_prev = min(c1, c3);

            // Update overall minimum subarray sum
            ans_min = min(ans_min, min_prev);
        }

        // If every element is negative,
        // sum - ans_min becomes 0, which is invalid.
        // In that case, return the normal Kadane answer.
        if (sum - ans_min == 0)
            return ans_max;

        // Maximum circular subarray sum
        int final_ans = max(ans_max, sum - ans_min);

        return final_ans;
    }
};
