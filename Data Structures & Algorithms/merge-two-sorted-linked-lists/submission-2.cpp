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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* curr1 = list1;
        ListNode* curr2 = list2;
        
        ListNode* next1 = NULL;
        ListNode*  prev1 = NULL;
        ListNode* next2 = NULL;
        ListNode* prev2 = NULL;
        while(curr1!=NULL && curr2!=NULL){
            next1 = curr1->next;
            next2 = curr2->next;
            if(curr1->val < curr2->val){ 
               curr1->next = curr2;
               if(prev2!=NULL)prev2->next = curr1;
               prev2 = curr1;
               curr1 = next1;
               prev1 = NULL;
            }
            else{
                curr2->next = curr1;
               if(prev1!=NULL) prev1->next = curr2;
                prev1 = curr2;
                curr2 = next2;
                prev2 = NULL;
            }
        }if(list1!=NULL && list2!=NULL){
            if(list1->val<list2->val){
                return list1;
            }
            else return list2;
        }
        else if(list1!=NULL && list2==NULL)return list1;
        else if(list1==NULL && list2!=NULL)return list2;
        else return NULL;
    
    }
};
