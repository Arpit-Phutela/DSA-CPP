// LeetCode 344 - Reverse String
// Approach: Two Pointers
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    void reverseString(vector<char>& s) {

        // Initialize two pointers
        int left = 0;
        int right = s.size() - 1;

        // Swap characters until both pointers meet
        while(left < right) {

            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;

            left++;
            right--;
        }
    }
};
