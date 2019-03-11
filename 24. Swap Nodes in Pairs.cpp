// 24. Swap Nodes in Pairs.cpp

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
    ListNode* swapPairs(ListNode* head) {
        
        ListNode* cur = head;
        ListNode* last = head;
        if(head != NULL && head->next != NULL)
            head = head->next;
        while(cur != NULL && cur->next != NULL){
            last->next = cur->next;
            ListNode* temp = cur->next->next;
            cur->next->next = cur;
            last = cur;
            cur = temp;
            last->next = cur;
        }
        return head;
    }
};

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
    ListNode* swapPairs(ListNode* head) {
        if(head && head->next){
            auto curr = head;
            head = curr->next;
            curr->next = swapPairs(curr->next->next);
            head->next=curr;
        }
        return head;
    }
};