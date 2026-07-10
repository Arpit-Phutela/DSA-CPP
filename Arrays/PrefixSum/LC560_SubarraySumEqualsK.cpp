// LeetCode 560 - Subarray Sum Equals K
// Approach: Prefix Sum + Hash Map
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        // Stores the current prefix sum
        int sum = 0;

        // Stores the total number of valid subarrays
        int count = 0;

        // Maps Prefix Sum -> Frequency
        unordered_map<int, int> Sum_Freq;

        // Prefix sum 0 occurs once before the array starts
        // This handles subarrays that begin from index 0
        Sum_Freq[0]++;

        for(int i = 0; i < nums.size(); i++)
        {
            // Update the current prefix sum
            sum = sum + nums[i];

            // Required previous prefix sum
            int target_sum = sum - k;

            // Number of times target_sum has occurred
            int Sum_Frequency = Sum_Freq[target_sum];

            // Every occurrence forms one valid subarray
            count = count + Sum_Frequency;

            // Store the current prefix sum
            Sum_Freq[sum]++;
        }

        return count;
    }
};
