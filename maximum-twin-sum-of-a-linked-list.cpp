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
    int pairSum(ListNode* head) {
        vector<int> vi;
        while(head != nullptr){
            vi.push_back(head->val);
            head = head->next;
        }
        int l = 0, r = vi.size() - 1;
        int maxS = 0;
        while(l < r){
            maxS = max(maxS, vi[l] + vi[r]);
            l++;
            r--;
        }
        return maxS;
    }
};