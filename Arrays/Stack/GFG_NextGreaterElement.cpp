// GFG - Next Greater Element
// Approach: Monotonic Stack
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> nextLargerElement(vector<int>& arr) {

        int n = arr.size();

        // Stores the answer for every element
        vector<int> ans(n, -1);

        // Monotonic decreasing stack
        stack<int> st;

        // Push the last element
        st.push(arr[n - 1]);

        // Traverse from right to left
        for(int i = n - 2; i >= 0; i--) {

            // Remove all smaller or equal elements
            while(!st.empty() && st.top() <= arr[i]) {
                st.pop();
            }

            // If stack becomes empty,
            // there is no greater element on the right
            if(st.empty()) {
                ans[i] = -1;
            }
            else {
                ans[i] = st.top();
            }

            // Push current element for future comparisons
            st.push(arr[i]);
        }

        return ans;
    }
};
