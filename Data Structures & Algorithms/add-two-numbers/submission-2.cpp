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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*temp = NULL;
        ListNode*prev = NULL;
        ListNode*newhead = NULL;
        int carry = 0,sum = 0,count = 0;
        ListNode*curr1 = l1;
        ListNode*curr2 = l2;
        while(curr1!=NULL || curr2!=NULL){
            if(curr1!=NULL && curr2!=NULL){
             sum = curr1->val+curr2->val+carry;
             curr1 = curr1->next;
             curr2 = curr2->next;
            }
            else if(curr1!=NULL && curr2==NULL){
             sum = curr1->val+carry;
             curr1 = curr1->next;
            }
            else if(curr1==NULL && curr2!=NULL){
             sum = curr2->val+carry;
             curr2 = curr2->next;
            }
            if(sum<10)carry = 0;
            else {
            carry = 1;
            sum = sum-10;
            }
            count++;
            temp = new ListNode(sum);
            if(count==1)newhead = temp;
            if(prev!=NULL)prev->next = temp;
            prev = temp;
        }//add the last carry here
        if(carry!=0){
          temp->next = new ListNode(carry);
        }
        return newhead;
    }
};
