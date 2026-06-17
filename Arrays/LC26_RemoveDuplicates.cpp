// LeetCode 26 - Remove Duplicates from Sorted Array
// Topic: Arrays, Two Pointers
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 0, right = 1;
        int n = nums.size();

        while (right < n) {
            if (nums[left] != nums[right]) {
                left++;
                nums[left] = nums[right];
            }
            right++;
        }

        return left + 1;
    }
};
