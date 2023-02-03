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
    pair<ListNode*, ListNode*> reverseGroup(ListNode* head, ListNode* last){
        if (head == nullptr || head->next == nullptr)
            return make_pair(head,head);
        ListNode *left = head;
        ListNode *right = head->next;
        left->next = nullptr;
        while (right != last)
        {
            ListNode *temp = right->next;
            right->next = left;
            left = right;
            right = temp;
        }
        return make_pair(left, head);
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode * dummy = new ListNode(0);
        dummy->next = head;
        ListNode* left = dummy;
        ListNode* last = head;
        while(last != nullptr){
            int m = k;
            while(last != nullptr && m > 0){
                last = last->next;
                m--;
            }
            if(m <= 0){
                pair<ListNode*, ListNode*> p = reverseGroup(left->next, last);
                left->next = p.first;
                p.second->next = last;
                left = p.second;
            }
        }
        return dummy->next;
    }
};