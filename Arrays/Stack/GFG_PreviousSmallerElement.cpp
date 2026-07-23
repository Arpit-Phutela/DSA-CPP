// GFG - Previous Smaller Element
// Approach: Monotonic Stack
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> prevSmaller(vector<int>& arr) {

        int n = arr.size();

        // Stores the previous smaller element for each index
        vector<int> ans(n, -1);

        // Monotonic increasing stack
        stack<int> st;

        // Push the first element
        st.push(arr[0]);

        // Traverse from left to right
        for(int i = 1; i < n; i++) {

            // Remove all elements greater than
            // or equal to the current element
            while(!st.empty() && arr[i] <= st.top()) {
                st.pop();
            }

            // If stack becomes empty,
            // no previous smaller element exists
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
