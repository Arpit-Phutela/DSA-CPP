// LeetCode 35 - Search Insert Position
// Approach: Binary Search
// Time Complexity: O(log n)
// Space Complexity: O(1)

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        // Initialize search boundaries
        int low = 0;
        int high = nums.size();
        int mid;

        // If target is greater than the last element,
        // it should be inserted at the end
        if(target > nums[high - 1]) {
            return high;
        }

        // Perform Binary Search
        while(low <= high) {

            mid = (low + high) / 2;

            // Target found
            if(nums[mid] == target) {
                return mid;
            }

            // Search in the left half
            if(target < nums[mid]) {
                high = mid - 1;
            }
            // Search in the right half
            else {
                low = mid + 1;
            }
        }

        // Target not found,
        // low indicates the correct insertion index
        return low;
    }
};
