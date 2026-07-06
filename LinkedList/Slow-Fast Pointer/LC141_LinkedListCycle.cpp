// LeetCode 141 - Linked List Cycle
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
    bool hasCycle(ListNode *head) {

        // Initialize slow and fast pointers
        ListNode* slow = head;
        ListNode* fast = head;

        // Move slow by one step and fast by two steps
        while((fast != nullptr) && (fast->next != nullptr)){

            slow = slow->next;
            fast = fast->next->next;

            // If both pointers meet,
            // a cycle exists in the linked list
            if(slow == fast){
                return true;
            }
        }

        // Fast pointer reached the end,
        // so no cycle exists
        return false;
    }
};
