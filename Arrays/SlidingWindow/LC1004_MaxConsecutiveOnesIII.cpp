// LeetCode 1004 - Max Consecutive Ones III
// Approach: Sliding Window
// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int left = 0;
        int right = 0;

        // Stores the number of zeroes present in the current window
        int zeroes = 0;

        // Stores the maximum valid window length found so far
        int ans = 0;

        int n = nums.size();

        while (right < n) {

            // Include current element in the window
            if (nums[right] == 0) {
                zeroes++;
            }

            // If zeroes exceed k, shrink the window
            while (zeroes > k) {


                if (nums[left] == 0) {
                    zeroes--;
                }

                left++;
            }

            // Current window is valid, update answer
            ans = max(ans, right - left + 1);

            // Expand window
            right++;
        }

        return ans;
    }
};
