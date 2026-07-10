// LeetCode 1991 - Find the Middle Index in Array
// Approach: Prefix Sum
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {

        // Stores the total sum of the array
        int sum = 0;

        // Stores the sum of elements on the left
        int left = 0;

        // Stores the sum of elements on the right
        int right = 0;

        // Calculate the total sum of the array
        for(int i = 0; i < nums.size(); i++) {
            sum = sum + nums[i];
        }

        // Check if index 0 is the middle index
        if(sum == nums[0])
            return 0;

        // Traverse the array
        for(int i = 1; i < nums.size(); i++) {

            // Add the previous element to the left sum
            left = left + nums[i - 1];

            // Calculate the right sum
            right = sum - nums[i] - left;

            // Check if the current index is the middle index
            if(left == right)
                return i;
        }

        // No middle index found
        return -1;
    }
};
