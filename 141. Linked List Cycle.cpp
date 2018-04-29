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
    bool hasCycle(ListNode *head) {
        ListNode * cur1, *cur2;
        if(head==NULL) return false;
        cur1 = head;
        cur2 = cur1->next;
        while(cur2!=NULL && cur2->next!=NULL && cur2->next->next!=NULL){
            cur1 = cur1->next;
            cur2 = cur2->next->next;
            if(cur1 == cur2)
                return true;
        }
        return false;
    }
};