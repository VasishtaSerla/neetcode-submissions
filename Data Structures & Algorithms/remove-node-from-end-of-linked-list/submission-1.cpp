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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*current = head;
        int size = 0;
        while(current!=NULL){
            size++;
            current = current->next;
        }
        if(n==size)return head->next;
        int bindex = size-n-1;
        current = head;
        for(int i = 0; i<bindex; i++){
            current = current->next;
        }
        if(current->next!=NULL){
            ListNode*temp = current->next->next;
            current->next = temp;
        }
        return head;
    }
};
