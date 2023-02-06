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
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* left = dummy;
        ListNode* right = head;
        while(right != nullptr){
            int val = right->val;
            bool dup = false;
            while(right->next != nullptr && right->next->val == val){
                ListNode* temp = right;
                right = right->next;
                delete temp;
                dup =  true;
            }
            if(dup){
                left->next = right->next;
            } else {
                left = right;
            }
            right = right->next;
            
        }
        return dummy->next;
    }
};