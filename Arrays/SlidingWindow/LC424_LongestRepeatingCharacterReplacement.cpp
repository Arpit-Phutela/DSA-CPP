// LeetCode 424 - Longest Repeating Character Replacement
// Approach: Sliding Window
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:

    // Function to find maximum frequency character
    // present in the current window
    int find(int hash[]) {

        int freq = -1;

        for(int i = 1; i < 256; i++) {
            freq = max(hash[i], freq);
        }

        return freq;
    }

    int characterReplacement(string s, int k) {

        int hash[256] = {0};

        int left = 0;
        int right = 0;

        int ans = 0;
        int len = 0;
        int freq = -1;
        int diff = -1;

        while(right < s.size()) {

            // Add current character into window
            hash[s[right]]++;

            // Find maximum frequency character
            freq = find(hash);

            // Current window length
            len = right - left + 1;

            // Characters that need replacement
            diff = len - freq;

            // Shrink window if replacements exceed k
            while(diff > k) {

                hash[s[left]]--;
                left++;

                freq = find(hash);

                len = right - left + 1;

                diff = len - freq;
            }

            // Update answer
            ans = max(ans, len);

            right++;
        }

        return ans;
    }
};
