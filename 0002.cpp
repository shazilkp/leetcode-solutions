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
    int length(ListNode * l){
        ListNode * t = l;
        int count = 0;
        while(t){
            t=t->next;
            count++;
        }
        return count;
    }
    void swap(ListNode * &l1,ListNode * &l2){
        ListNode * t = l1;
        l1 = l2;
        l2 = t;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int size1 = length(l1);
        int size2 = length(l2);
        cout << " "<<size1 <<" "<< size2<< "\n";
        if(size2 > size1){
            swap(l1,l2);
        }
        int carry = 0;
        ListNode *l1copy = l1;
        ListNode * prev = NULL;
        while(l1){
            cout << l1->val << "\n";
            int t = l1->val + (l2 ? l2->val : 0) + carry;
            l1->val = t % 10;
            carry = t / 10;
            if(l2){
                l2 = l2->next;
            }
            prev = l1;
            l1 = l1->next;
        }

        if(carry){
            ListNode * end = new ListNode(carry);
            prev->next = end;
        }
        return l1copy;
    }
};
