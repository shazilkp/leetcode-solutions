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
        if(!head){
            return false;
        }
        ListNode * first = head;
        ListNode * second = head;

        
        while(1){
            if(!first->next || !second->next || !second->next->next){
                return false;
            }
            first = first->next;
            second = second->next->next;
            if(first == second){
                return true;
            }
        }

    }
};
