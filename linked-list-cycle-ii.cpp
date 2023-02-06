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
        ListNode* dummy = new ListNode(0);
        dummy->next = head;   
        ListNode* fast = head;
        bool flag = false;
        while(fast && fast->next){
            head = head->next;
            fast = fast->next->next;
            if(head == fast) {
                flag = true;
                break;
            }
        }
        if(flag){
            head = dummy->next;
            while(fast != head){
                fast = fast->next;
                head = head->next;
            }
            return fast;
        }
         return nullptr;
    }
};