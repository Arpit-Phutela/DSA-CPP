// LeetCode 75 - Sort Colors
// Approach: Dutch National Flag Algorithm
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int n = nums.size();
        int high = n-1;
        while(mid <= high){
            if ( nums[mid] == 0){
                int temp = nums[low];
                nums[low] = nums[mid];
                nums[mid] = temp;
                low++;
                mid++; 

            }else if (nums[mid] == 1){
                mid++;

            }else{
                int temp = nums[high];
                nums[high] = nums [mid];
                nums[mid] = temp;
                high--;

            }
        }
        
    }
};
