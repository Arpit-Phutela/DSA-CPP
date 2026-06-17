// LeetCode 209 - Minimum Size Subarray Sum
// Approach: Sliding Window
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int low = 0 , high = 0 , n = nums.size();
        int ans = INT_MAX;
        int sum = 0;
        while(high < n)
        {
            sum = sum + nums[high];
            while ( sum >= target)
            {
                ans = min(ans,high - low +1);
                sum = sum - nums[low];
                low++;
            }
            high++;
        } if (ans == INT_MAX) return 0;
        return ans;  
    }
};
