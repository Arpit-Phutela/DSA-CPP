// LeetCode 80 - Remove Duplicates from Sorted Array II
// Topic: Arrays, Two Pointers
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int allocated = 0;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            if(allocated < 2 || nums[i] != nums[allocated-2]){
                nums[allocated] = nums[i];
                allocated++;
            }
        }
        return allocated;    
    }
};
