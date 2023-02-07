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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        while(list1 && list2){
            if(list1->val > list2->val){
                curr->next = new ListNode(list2->val);
                list2 = list2->next;
            }else {
                curr->next = new ListNode(list1->val);
                list1 = list1->next;
            }
            curr = curr->next;
        }
        while(list1){
            curr->next = new ListNode(list1->val);
            list1 = list1->next;
            curr = curr->next;
        }
        while(list2){
            curr->next = new ListNode(list2->val);
            list2 = list2->next;
            curr = curr->next;
        }
        return dummy->next;
    }
};