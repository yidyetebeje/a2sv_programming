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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* left = head;
        ListNode* right = head->next;
        while(right != NULL){
            if(left->val == right->val){
                left->next = left->next->next;
                right = right->next;
            } else{
                left = left->next;
                right = right->next;
            }
        }   
        return head;
    }
};