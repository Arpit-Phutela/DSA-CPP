// LeetCode 724 - Find Pivot Index
// Approach: Prefix Sum
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        // Stores the sum of all elements
        int sum = 0;

        // Stores the sum of elements on the left of the current index
        int left = 0;

        // Stores the sum of elements on the right of the current index
        int right = 0;

        // Calculate the total sum of the array
        for(int i = 0; i < nums.size(); i++) {
            sum = sum + nums[i];
        }

        // Check if index 0 is the pivot index
        if(sum == nums[0])
            return 0;

        // Traverse the array
        for(int i = 1; i < nums.size(); i++) {

            // Add the previous element to the left sum
            left = left + nums[i - 1];

            // Calculate the right sum
            right = sum - nums[i] - left;

            // Check if current index is the pivot
            if(left == right)
                return i;
        }

        // No pivot index found
        return -1;
    }
};
