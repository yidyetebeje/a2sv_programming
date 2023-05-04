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
 class Compare {
public:
    bool operator()(ListNode* below, ListNode* above)
    {
        return below->val > above->val;
    }
};
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode* dummy = new ListNode(0);
        ListNode* list = dummy;
        priority_queue<ListNode*,vector<ListNode*>, Compare> pq;
        for(auto li: lists){
            if(li) pq.push(li);
        }
        while(pq.size() > 0){
            ListNode* x = pq.top();
            pq.pop();
            list->next = x;
            list = list->next;
            if(x && x->next) pq.push(x->next);
        }
        return dummy->next;
    }
};