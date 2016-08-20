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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL, * tail = NULL;
        int result, carry = 0;
        while(l1 || l2) {
            result = carry;
            if(l1) {
                result += l1->val;
                l1 = l1->next;
            }
            if(l2) {
                result += l2->val;
                l2 = l2->next;
            }
            carry = result / 10;
            result %= 10;
            if(tail) {
                tail->next = new ListNode(result);
                tail = tail->next;
            }
            else {
                tail = new ListNode(result);
                head = tail;
            }
        }
        if(carry > 0) {
            tail->next = new ListNode(carry);
        }
        return head;
    }
};
