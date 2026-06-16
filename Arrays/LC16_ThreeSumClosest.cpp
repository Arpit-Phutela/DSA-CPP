// LeetCode 16 - 3Sum Closest
// Topic: Arrays, Sorting, Two Pointers
// Time Complexity: O(n^2)
// Space Complexity: O(1)

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());

        int max_diff = INT_MAX;
        int diff;
        int ans;

        int n = nums.size();

        for(int i = 0 ; i < n-2; i++){
            int left = i+1;
            int right = n-1;

            while(left < right){

                int sum = nums[i] + nums[left] + nums[right];

                if(sum == target){
                    return target;
                }

                diff = abs(sum - target);

                if(sum < target){

                    if(diff < max_diff){
                        max_diff = diff;
                        ans = sum;
                    }

                    left++;
                }
                else{

                    if(diff < max_diff){
                        max_diff = diff;
                        ans = sum;
                    }

                    right--;
                }
            }
        }

        return ans;
    }
};
