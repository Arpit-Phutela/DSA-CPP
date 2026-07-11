// LeetCode 525 - Contiguous Array
// Approach: Prefix Sum + Hash Map
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        // Stores the maximum length of a valid subarray
        int ans = 0;

        // Counts the number of 0s and 1s seen so far
        int zero = 0;
        int one = 0;

        // Maps (one - zero) difference -> first occurrence index
        unordered_map<int, int> diff_index;

        for(int i = 0; i < nums.size(); i++)
        {
            // Update the count of 0s and 1s
            if(nums[i] == 0)
                zero++;
            else
                one++;

            // Difference between number of 1s and 0s
            int diff = one - zero;

            // If the difference becomes 0,
            // the subarray from index 0 to i is valid
            if(diff == 0)
                ans = max(ans, i + 1);

            // Store the first occurrence of this difference
            if(diff_index.find(diff) == diff_index.end())
            {
                diff_index[diff] = i;
            }
            else
            {
                // Previous occurrence of the same difference
                int index = diff_index[diff];

                // Subarray between the two indices has
                // equal number of 0s and 1s
                ans = max(ans, i - index);
            }
        }

        return ans;
    }
};
