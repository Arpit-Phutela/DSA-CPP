// LeetCode 1047 - Remove All Adjacent Duplicates In String
// Approach: Stack
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    string removeDuplicates(string s) {

        // Stack to store the characters
        stack<char> str;

        // Stores the final answer
        string ans;

        for(int i = 0; i < s.size(); i++) {

            // If the stack is empty,
            // simply push the current character
            if(str.empty()) {

                str.push(s[i]);
                continue;
            }

            // If the current character matches the top,
            // remove the duplicate pair
            if(s[i] == str.top()) {

                str.pop();
                continue;
            }

            // Otherwise, push the current character
            str.push(s[i]);
        }

        // Build the answer from the stack
        while(!str.empty()) {

            ans.push_back(str.top());
            str.pop();
        }

        // Reverse because stack gives characters
        // in reverse order
        reverse(ans.begin(), ans.end());

        return ans;
    }
};
