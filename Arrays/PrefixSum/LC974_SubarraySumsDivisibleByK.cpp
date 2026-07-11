// LeetCode 974 - Subarray Sums Divisible by K
// Approach: Prefix Sum + Hash Map
// Time Complexity: O(n)
// Space Complexity: O(k) (or O(n) in the worst case)

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        // Stores the frequency of each remainder
        unordered_map<int, int> remainder_freq;

        // Empty prefix has remainder 0
        remainder_freq[0]++;

        // Stores the current prefix sum
        int sum = 0;

        // Stores the total number of valid subarrays
        int count = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            // Update the prefix sum
            sum = sum + nums[i];

            // Calculate the remainder of the current prefix sum
            int target_remainder = sum % k;

            // Handle negative remainders
            if(target_remainder < 0){
                target_remainder = target_remainder + k;
            }

            // Every previous occurrence of the same remainder
            // forms a valid subarray divisible by k
            count = count + remainder_freq[target_remainder];

            // Store the current remainder
            remainder_freq[target_remainder]++;
        }

        return count;
    }
};
