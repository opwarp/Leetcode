// 234. Palindrome Linked List.cpp
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
    bool isPalindrome(ListNode* head) {
        ListNode* cur = head;
        int l = 0;
        while(cur != NULL){
            cur = cur->next;
            l++;
        }
        l = l/2; //half length of link
        if(l>0){ //half length over 1
            cur = head;
            while(l-1>0){
               cur = cur->next;
                l--;
            }
            ListNode* last = cur; //the last noed of first half
            cur = cur->next; //cur become the head of second half
            last->next = NULL; //give end to the first half
            //revert the second half
            last = cur;
            cur = cur->next;
            last->next=NULL;
            while(cur!=NULL){
                ListNode* tmp = cur;
                cur = cur->next;
                tmp->next=last;
                last = tmp;
            }
            cur = head;
            ListNode* cur2 = last; //head of the reverted second half
            while(cur!=NULL){ //compare two half
                if(cur->val != cur2->val)
                    return false;
                cur=cur->next;
                cur2=cur2->next;
            }
            return true;
        }
        return true;
    }
};