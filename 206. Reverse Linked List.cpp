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
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        if(cur==NULL){return cur;}
        ListNode* next = cur->next;
        ListNode* last = NULL;
        cur->next = last;
        last = cur;
        cur = next;
        while(cur != NULL){
            next = cur->next;//next = cur->next(which is address a), next = b, cur->next is still a, because they are not same pointer variable. '=' in pointer varialbes means copy the address value of pointers
            cur->next = last;
            last = cur;
            cur=next;
        }
        return last;       
    }
};