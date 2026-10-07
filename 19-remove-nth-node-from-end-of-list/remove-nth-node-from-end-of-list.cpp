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
    int length(ListNode* head) {
        int len = 0;
        while (head != NULL) {
            len++;
            head = head->next;
        }
        return len;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = length(head);
        if (len <= n) {
            head = head->next;
            return head;
        }
        int l = len - n;
        ListNode* temp = head;
        for (int i = 1; i < l; i++) {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;
    }
};