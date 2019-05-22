// 160. Intersection of Two Linked Lists.cppasqw
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// class Solution {
// public:
//     ListNode* revert(ListNode* head) {
//         ListNode *last = head;
//         if(head==NULL) return NULL;
//         ListNode *cur = head->next;
//         if(cur==NULL) return head;
//         last->next = NULL;
//         while(cur!=NULL){
//             ListNode *tmp = cur;
//             cur=cur->next;
//             tmp->next=last;
//             last = tmp;
//         }
//         return last;
//     }
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         headA = revert(headA);
//         headB = revert(headB);
//         ListNode *cura = headA;
//         ListNode *curb = headB;
//         ListNode *res = NULL;
//         while(cura != NULL && curb != NULL){
//             if(cura->val == curb->val)
//                 res = cura;
//             else
//                 break;
//         }
//         headA = revert(headA);
//         headB = revert(headB);
//         return res;
//     }
// };

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *cura = headA;
        ListNode *curb = headB;
        while(cura != NULL && curb != NULL){
            if(cura == curb)
                return cura;
            cura = cura->next;
            curb = curb->next;
            if(cura == NULL && curb == NULL)
                return NULL;
            if(cura == NULL){
                cura = headA;
            }
            if(curb == NULL){
                curb = headB;
            }
        }
        return NULL;
    }