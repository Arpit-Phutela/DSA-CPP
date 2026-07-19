// LeetCode 20 - Valid Parentheses
// Approach: Stack
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    bool isValid(string s) {

        // Stack to store opening brackets
        stack<char> st;

        for(int i = 0; i < s.size(); i++) {

            // Push opening brackets
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {

                st.push(s[i]);
            }
            // Process closing brackets
            else {

                // No matching opening bracket
                if(st.empty())
                    return false;

                // Matching pair found
                if(st.top() == '(' && s[i] == ')')
                    st.pop();

                else if(st.top() == '{' && s[i] == '}')
                    st.pop();

                else if(st.top() == '[' && s[i] == ']')
                    st.pop();

                // Mismatched bracket
                else
                    return false;
            }
        }

        // Stack should be empty if all brackets matched
        return st.empty();
    }
};
