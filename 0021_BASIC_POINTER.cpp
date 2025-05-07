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
        if(!list1 && !list2){
            return list1;
        }

        if(!list1 && list2){
            return list2;
        }

        if(!list2 && list1){
            return list1;
        }

        if(list1->val > list2->val){
            ListNode * temp = list2;
            list2 = list1;
            list1 = temp;
        }
       
        ListNode * l1 = list1;
        ListNode * l2 = list2;
        
        ListNode * l1Prev = NULL;

        

        while(l2){
            if(!l1){
                l1Prev->next = l2;
                break;
            }
            if(l1->val <= l2->val){
                l1Prev = l1;
                l1=l1->next;
            }
            else{
                ListNode * l2next = l2->next;
                l1Prev->next = l2;
               
                    
                
                l2->next = l1;
                l1Prev = l2;
                l2 = l2next;
                

            }
        }
        return list1;
    }
};
