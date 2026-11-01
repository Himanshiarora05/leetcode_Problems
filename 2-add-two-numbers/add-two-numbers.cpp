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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* a = l1;
        ListNode* b = l2;
        ListNode* temp = new ListNode(200);
        ListNode* c = temp;
        int carry = 0;
        while (a != NULL || b != NULL) {
            int sum = carry;
            if (a)  sum += a->val;
            if (b)  sum += b->val;

            ListNode* newNode = new ListNode(sum % 10);
            c->next = newNode;
            c = c->next;
            carry = sum / 10;

            if (a)  a = a->next;
            if (b)  b = b->next;
        }
        if (carry) {
            ListNode* newNode = new ListNode(carry);
            c->next = newNode;
            c = c->next;
        }
        return temp->next;
    }
};