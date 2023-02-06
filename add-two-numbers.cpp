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
        int carry = 0;
        ListNode* dummy = new ListNode(0);
        ListNode* head = dummy;
        while(l1 != nullptr && l2 != nullptr){
            int val = l1->val + l2->val + carry;
            if(val > 9){
                carry = 1;
                val = val % 10;
            } else {
                carry = 0;
            }
            ListNode* newNode = new ListNode(val);
            head->next = newNode;
            head = head->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != nullptr){
            int val = l1->val + carry;
            if(val > 9){
                carry = 1;
                val = val % 10;
            } else {
                carry = 0;
            }
            ListNode* newNode = new ListNode(val);
            head->next = newNode;
            head = head->next;
            l1 = l1->next;
        }
        while(l2 != nullptr){
            int val = l2->val + carry;
            if(val > 9){
                carry = 1;
                val = val % 10;
            } else {
                carry = 0;
            }
            ListNode* newNode = new ListNode(val);
            head->next = newNode;
            head = head->next;
            l2 = l2->next;
        }
        if(carry != 0){
            ListNode* newNode = new ListNode(carry);
            head->next = newNode;
            head = head->next;
        }
        return dummy->next;
    }
};