// LeetCode 287 - Find the Duplicate Number
// Approach: Floyd's Cycle Detection (Tortoise and Hare)
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        // Initialize slow and fast pointers
        int slow = 0, fast = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++) {

            // Move slow pointer one step
            slow = nums[slow];

            // Move fast pointer two steps
            fast = nums[fast];
            fast = nums[fast];

            // Cycle detected
            if (slow == fast) {

                // Move slow pointer back to the start
                slow = 0;

                // Move both pointers one step at a time
                // They will meet at the duplicate number
                while(slow != fast) {

                    slow = nums[slow];
                    fast = nums[fast];
                }

                // Duplicate number found
                return slow;
            }
        }

        // This line will never be reached for valid inputs
        return -1;
    }
};
