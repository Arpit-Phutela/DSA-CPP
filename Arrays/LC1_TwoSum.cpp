// LeetCode 1 - Two Sum
// Approach: Hash Map
// Time Complexity: O(N)
// Space Complexity: O(N)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // Stores {number, index}
        unordered_map<int, int> mpp;

        for (int i = 0; i < nums.size(); i++) {

            // Number required to reach the target
            int need = target - nums[i];

            // If required number already exists,
            // we have found the answer
            if (mpp.find(need) != mpp.end()) {
                return {mpp[need], i};
            }

            // Store current number and its index
            mpp[nums[i]] = i;
        }

        return {};
    }
};
