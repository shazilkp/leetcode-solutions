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
    ListNode *detectCycle(ListNode *head) {
        if(!head){
            return NULL;
        }
        unordered_map<ListNode *, bool> mp;
        ListNode * t = head;
        while(1){
            if(mp[t] == NULL || mp[t] == false){
                mp[t] = true;
            }
            else{
                return t;
            }
            if(!t->next){
                return NULL;
            }
            t = t->next;
        }
    }
};
