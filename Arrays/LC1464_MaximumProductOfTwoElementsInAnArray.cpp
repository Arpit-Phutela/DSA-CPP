// LeetCode 1464 - Maximum Product of Two Elements in an Array
// Approach: Greedy
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int n = nums.size();

        // Stores the maximum product found so far
        int ans = 0;

        // Stores the largest element seen so far
        int curMax = nums[0];

        // Traverse the array
        for(int i = 1; i < n; i++) {

            // Calculate the product using the current
            // maximum element and the current number
            ans = max(ans, (curMax - 1) * (nums[i] - 1));

            // Update the maximum element
            curMax = max(curMax, nums[i]);
        }

        return ans;
    }
};
