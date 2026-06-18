// LeetCode 3 - Longest Substring Without Repeating Characters
// Approach: Sliding Window + Hash Map
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int left = 0 , right = 0 , ans = 0;
        unordered_map<char,int>mpp;
        int n = s.size();

        while(right  < n)
        {

            mpp[s[right]]++;

            // If this condition becomes true,
            // it means a duplicate character exists in the window
            while(mpp.size() < right-left+1){

                mpp[s[left]]--;

                if(mpp[s[left]] == 0){
                    mpp.erase(s[left]);
                }

                left++;
            }

            // Update answer with current valid window length
            ans = max(ans,right-left+1);

            right++;
        }

        return ans;
    }
};