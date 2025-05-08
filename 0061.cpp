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
    int listLength(ListNode * head){
        ListNode * k = head;
        int count = 0;
        while(k){
            k=k->next;
            count++;
        }
        return count;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        int len = listLength(head);
        if(k == 0 || len == 0){
            return head;
        }

        int numRot = k % len;
        if(numRot == 0){
            return head;
        }

        ListNode * t = head;
        ListNode * tail = NULL;
        ListNode * newHead = NULL;

        for(int i = 0; i < len; i++){
            
            if(i == len - numRot - 1){
                tail = t;
                newHead = t->next;
                tail->next = NULL;
                t = newHead;
                continue;
            }

            if(i == len - 1){
                if(!t->next){
                    t->next = head;
                }
            }
            t = t->next;
        }
        return newHead;

    }
};
