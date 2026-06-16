// LeetCode 977 - Squares of a Sorted Array
// Topic: Arrays, Two Pointers
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;
        vector<int> ans;
        int n = nums.size();

        for(int i = 0; i< n;i++){
            if(nums[i] >= 0){
                pos.push_back(nums[i]);
            }
            else{
                neg.push_back(nums[i]);
            }
        }

        for(int i = 0 ; i < pos.size() ; i++){
            pos[i] *= pos[i];
        }

        for(int i = 0 ; i < neg.size() ; i++){
            neg[i] *= neg[i];
        }

        reverse(neg.begin(),neg.end());

        int i = 0;
        int j = 0;

        while (i < pos.size() && j < neg.size()){
            if (pos[i] < neg[j]){
                ans.push_back(pos[i]);
                i++;
            }
            else{
                ans.push_back(neg[j]);
                j++;
            }
        }

        while(j < neg.size()){
            ans.push_back(neg[j]);
            j++;
        }

        while(i < pos.size()){
            ans.push_back(pos[i]);
            i++;
        }

        return ans;    
    }
};
