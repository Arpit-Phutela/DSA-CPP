// LeetCode 142 - Linked List Cycle II
// Approach: Floyd's Cycle Detection (Tortoise and Hare)
// Time Complexity: O(n)
// Space Complexity: O(1)

 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        // Initialize slow and fast pointers
        ListNode *slow = head, *fast = head;

        // Move slow by 1 step and fast by 2 steps
        while ((fast != nullptr) && (fast->next != nullptr))
        {
            slow = slow->next;
            fast = fast->next->next;

            // Cycle detected
            if (slow == fast) {

                // Move fast back to head
                fast = head;

                // Move both pointers one step at a time
                // They will meet at the starting node of the cycle
                while (fast != slow) {

                    fast = fast->next;   // Start from head
                    slow = slow->next;   // Start from meeting point
                }

                // Starting node of the cycle
                return fast;
            }
        }

        // No cycle present
        return NULL;
    }
};
