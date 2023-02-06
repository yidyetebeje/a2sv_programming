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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* traverse = head;
        ListNode* last = head;
        int count = 0;
        while(traverse != nullptr){
            last = traverse;
            traverse = traverse->next;
            count++;
        }
        cout << count << endl;
        k = k % count;
        if(k == 0) return head;
        int range = count - k - 1;
        traverse = head;
        while(range){
            traverse = traverse->next;
            range--;
        }
        ListNode* dummy = traverse->next;
        traverse->next = nullptr;
        last->next = head;
        return dummy;
    }
};