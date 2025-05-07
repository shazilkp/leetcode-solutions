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
    void printList(ListNode* head) {
        while (head != nullptr) {
            std::cout << head->val;
            if (head->next) std::cout << " -> ";
            head = head->next;
        }
        std::cout << std::endl;
    }

    ListNode* reverse(ListNode* head, int n){
        int i = 0;
        ListNode * t = head;
        ListNode * prev = NULL;
        ListNode * next = t->next;
        while(i < n){
            next = t->next;
            t->next = prev;
            prev = t;
            t = next;
            i++;
        }
        head->next = t;
        
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
       
        ListNode * currHead = head;
        ListNode * prev = NULL;
        int loop = 0;
        while(1){
            int i = 0;
            ListNode * t = currHead;
            while(i < k && t){
                t=t->next;
                i++;
            }
            if(i < k){
                break;
            }
            if(i == k){
                if(loop != 0){
                    prev->next = reverse(currHead,k);
                    //printList(currHead);
                }
                else{
                    head = reverse(currHead,k);
                }  
            }
            prev = currHead;
            currHead = t;
            loop++;
        }
        return head;
    }
};
