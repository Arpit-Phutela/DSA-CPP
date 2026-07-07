// LeetCode 876 - Middle of the Linked List
// Approach: Slow and Fast Pointer
// Time Complexity: O(n)
// Space Complexity: O(1)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* middleNode(ListNode* head) {

        // Initialize slow and fast pointers
        ListNode *slow = head, *fast = head;

        // Move slow by one step and fast by two steps
        while (fast && fast->next) {

            slow = slow->next;
            fast = fast->next->next;
        }

        // Slow pointer will be at the middle node
        return slow;
    }
};
