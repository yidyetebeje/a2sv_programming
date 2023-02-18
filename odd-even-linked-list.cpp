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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return head;
        ListNode* head1 = head;
        ListNode* head2 = head -> next;
        if(!head2) return head;
        ListNode* next1 = NULL;
        ListNode* next2 = NULL;
        ListNode* temp = head -> next;
        while(head1 -> next || head2 -> next){
            if(head1 -> next){
                next1 = head1 -> next -> next;
                if(next1) {head1 -> next = next1; head1 = next1;}
                else head1 -> next = NULL;
            }
            if(head2 -> next){
                next2 = head2 -> next -> next;
                if(next2){ head2 -> next = next2; head2 = next2;}
                else head2 -> next = NULL;
            }
        }
        head1 -> next = temp;
        return head;
    }
};