// GFG - Previous Greater Element
// Approach: Monotonic Stack
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> preGreaterEle(vector<int>& arr) {

        int n = arr.size();

        // Stores the previous greater element for each index
        vector<int> ans(n, -1);

        // Monotonic decreasing stack
        stack<int> st;

        // Push the first element
        st.push(arr[0]);

        // Traverse from left to right
        for(int i = 1; i < n; i++) {

            // Remove all smaller or equal elements
            while(!st.empty() && st.top() <= arr[i]) {
                st.pop();
            }

            // If stack becomes empty,
            // no previous greater element exists
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
