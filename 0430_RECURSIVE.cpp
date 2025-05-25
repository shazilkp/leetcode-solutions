/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node * helper(Node * head){
        Node * t = head;
        Node * prev = NULL;
        while(t){
            if(t->child){
               Node * next = helper(t->child);
               Node * tnext = t->next;
               t->next = t->child;
               t->child->prev = t;
               t->child = NULL;
               next->next = tnext;
               if(tnext){
                tnext->prev = next;
               }
               //next->next->prev = next;
               prev = next;
               t = tnext;
               continue; 
            }
            prev = t;
            t = t->next;
        }
        return prev;
    }

    Node* flatten(Node* head) {
        helper(head);

        return head;
    }
};
