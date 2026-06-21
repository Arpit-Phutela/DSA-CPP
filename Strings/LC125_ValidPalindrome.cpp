// LeetCode 125 - Valid Palindrome
// Approach: Two Pointers
// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution {
public:
    bool isPalindrome(string s) {

        // Pointer starting from the beginning
        int start = 0;

        // Pointer starting from the end
        int end = s.size() - 1;

        while (start <= end) {

            // Skip non-alphanumeric characters from the left
            if (!isalnum(s[start])) {
                start++;
                continue;
            }

            // Skip non-alphanumeric characters from the right
            if (!isalnum(s[end])) {
                end--;
                continue;
            }

            // If characters do not match, it is not a palindrome
            if (tolower(s[start]) != tolower(s[end]))
                return false;

            // Move both pointers inward when characters match
            else {
                start++;
                end--;
            }
        }

        return true;
    }
};
