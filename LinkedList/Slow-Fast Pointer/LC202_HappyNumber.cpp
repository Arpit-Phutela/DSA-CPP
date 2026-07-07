// LeetCode 202 - Happy Number
// Approach: Floyd's Cycle Detection (Slow & Fast Pointer)
// Time Complexity: O(log n)
// Space Complexity: O(1)

class Solution {
public:

    // Function to calculate the sum of squares of digits
    int sq(int num){

        int sum = 0;

        while (num > 0) {

            int d = num % 10;
            sum += d * d;
            num /= 10;
        }

        return sum;
    }

    bool isHappy(int n) {

        // Initialize slow and fast pointers
        int slow = n, fast = n;

        // Continue until fast becomes 1
        while(fast != 1){

            // Move slow pointer one step
            slow = sq(slow);

            // Move fast pointer two steps
            fast = sq(fast);
            fast = sq(fast);

            // If both pointers meet before reaching 1,
            // a cycle exists and the number is not happy
            if (slow == fast && fast != 1)
                return false;
        }

        // Fast reached 1, so the number is happy
        return true;
    }
};
