// GFG - Next Smaller Element
// Approach: Monotonic Stack
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> nextSmallerEle(vector<int>& arr) {

        int n = arr.size();

        // Stores the next smaller element for each index
        vector<int> ans(n);

        // Monotonic increasing stack
        stack<int> s;

        // Sentinel value
        s.push(-1);

        // Traverse from right to left
        for(int i = n - 1; i >= 0; i--) {

            int curr = arr[i];

            // Remove all elements greater than
            // or equal to the current element
            while(s.top() >= curr) {
                s.pop();
            }

            // Top of the stack is the next smaller element
            ans[i] = s.top();

            // Push current element for future comparisons
            s.push(curr);
        }

        return ans;
    }
};
