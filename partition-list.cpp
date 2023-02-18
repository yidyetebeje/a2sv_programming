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
    ListNode* partition(ListNode* head, int x) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* left = dummy;
        ListNode* right = dummy;
        while(right != NULL){
            while(right->next && right->next->val < x){
                if(left == right){
                    left = left->next;
                    right = right->next;
                } else {
                    ListNode *temp = right->next;
                    right->next = temp->next;
                    temp->next = left->next;
                    left->next = temp;
                    left = left->next;
                }
            }
            if(right == nullptr && right->next == nullptr) break;
            right = right->next;
        }
        return dummy->next;
    }
};