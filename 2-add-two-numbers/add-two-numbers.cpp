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
        while(a || b|| carry){
            int sum = carry;
            if(a){
                sum += a->val;
                a = a->next;
            }
            if(b){
                sum += b->val;
                b = b->next;
            }
            ListNode* newNode = new ListNode(sum%10);
            carry = sum/10;
            c->next = newNode;
            c = c->next;
        }
        return temp->next;
    }
};