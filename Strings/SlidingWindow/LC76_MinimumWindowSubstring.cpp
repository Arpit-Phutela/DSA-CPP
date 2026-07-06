// LeetCode 76 - Minimum Window Substring
// Approach: Sliding Window + Frequency Array
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    string minWindow(string s, string t) {

        // Stores the frequency required from string t
        vector<int> need(256, 0);

        // Stores the frequency currently present in the window
        vector<int> have(256, 0);

        // Build the required frequency map
        for(int i = 0; i < t.size(); i++)
        {
            need[t[i]]++;
        }

        int left = 0;
        int right = 0;

        // Number of characters currently matched
        int matched = 0;

        // Variables to store the minimum window
        int ans_len = INT_MAX;
        int ans_start = -1;

        while(right < s.size())
        {
            // Add current character to the window
            have[s[right]]++;

            // Count only if this character was actually required
            if(have[s[right]] <= need[s[right]])
            {
                matched++;
            }

            // If all characters are matched,
            // try shrinking the window
            while(matched == t.size())
            {
                int current_len = right - left + 1;

                // Update answer if a smaller valid window is found
                if(current_len < ans_len)
                {
                    ans_len = current_len;
                    ans_start = left;
                }

                // Remove leftmost character
                have[s[left]]--;

                // If removing it breaks the requirement,
                // the window becomes invalid
                if(have[s[left]] < need[s[left]])
                {
                    matched--;
                }

                left++;
            }

            // Expand the window
            right++;
        }

        // No valid window found
        if(ans_start == -1)
        {
            return "";
        }

        // Return the minimum window substring
        return s.substr(ans_start, ans_len);
    }
};
