// LeetCode 344 - Reverse String
// Approach: Stack
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    void reverseString(vector<char>& s) {

        // Stack to store all characters
        stack<char> str;

        // Push every character into the stack
        for(int i = 0; i < s.size(); i++) {
            str.push(s[i]);
        }

        // Index for updating the original string
        int i = 0;

        // Pop characters and overwrite the array
        while(!str.empty()) {

            s[i] = str.top();
            str.pop();
            i++;
        }
    }
};
