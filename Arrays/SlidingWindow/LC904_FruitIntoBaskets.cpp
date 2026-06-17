// LeetCode 904 - Fruit Into Baskets
// Approach: Sliding Window + Hash Map
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0 , right = 0 , ans = 0;
        unordered_map<int,int>mpp;
        int n = fruits.size();
        while(right < n){
            mpp[fruits[right]]++;
            while( mpp.size() > 2 ){
                mpp[fruits[left]]--;
                if (mpp[fruits[left]] == 0){
                    mpp.erase(fruits[left]);
                }
                left++;
            }
                ans = max(ans,right - left + 1);
            right++;
        }return ans;
    }
};
